EXTRAFLAGS		= -g -Wall -Werror -DMONGO_HAVE_STDINT
CXXFLAGS		+=  -DUSER_TOPIC_STREAM_SERVER
INCLUDES		=  -I/usr/local/include

CXXFLAGS		= $(INCLUDES) $(EXTRAFLAGS)

LIBS		= -lpthread \
	          -lboost_system \
	          -lboost_program_options \
	          -lboost_date_time \
	          -lboost_thread \

AR		= ar rc
CP		= cp -f
RM		= rm -f

OBJS		= Scorer.o \
	        ComPosMatchScorer.o FansScorer.o LocScorer.o NameScorer.o \
	        PosMatchScorer.o TagScorer.o UserScorer.o WorkScorer.o \
	        YearScorer.o
T		= scoring

all: $(OBJS)

clean:
	$(RM) $(T) $(OBJS) 
