#!/bin/bash

PID_BASE=20000
BASE_DIR=/usr/local/user_search_engine_dev
SEARCH_BIN=$BASE_DIR/user_search_engine_dev

pushd $BASE_DIR

pid_list=""
for i in `seq 0 7`;
do
    port=$(($PID_BASE+$i))
    $SEARCH_BIN --port $port --index-dir /ram/current_user_index/user_index.$i/ --server-type user --mongodb-addr uc06:27017 --contacts-company-file /zdisk_nfs/zhaopin_serving_data/search_engine_data/contacts_company_name &
    pid_list="$pid_list $!"
done 
echo "All partition started"

while [ 1 ]
do
    for pid in $pid_list
    do
        kill -URG $pid
        if [ $? -ne 0 ]
        then
            for pid in $pid_list
            do
                kill $pid
            done
            echo "Some partitions are down. For all exit."
            exit
        else
            continue
        fi
    done
    sleep 1
done


