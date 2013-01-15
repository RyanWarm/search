EXTRAFLAGS		= -g -Wall -Werror 
INCLUDES		=  -I/usr/local/include

CXXFLAGS        = $(INCLUDES) $(EXTRAFLAGS) 

LIBS			= -lpthread \
				  -lboost_system \
				  -lboost_filesystem \
				  -lboost_program_options \
				  -lboost_date_time \
				  -lboost_thread \
				  -L/usr/local/lib -lxapian -lprotobuf \
				  -lmongoc \
				  -lcrypto \
				  -lmemcached \
				  -L../ -lranking

AR              = ar rc
CP				= cp -f 
RM				= rm -f 

OBJS			= test_blending.o 
T		= t 

all: $(T) 

$(T): $(OBJS) 
	$(CXX)  $(CXXFLAGS) -o $@  $^ $(LIBS)

clean:
	$(RM) $(T) $(OBJS) 


