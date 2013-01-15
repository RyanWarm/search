EXTRAFLAGS		= -g -Wall -Werror 
INCLUDES		=  -I/usr/local/include

CXXFLAGS        = $(INCLUDES) $(EXTRAFLAGS) 

LIBS			= -lpthread 

AR              = ar rc
CP				= cp -f 
RM				= rm -f 

OBJS			= RankingUtils.o
T		= libranking.a 

all: $(T) 

$(T): $(OBJS) 
	$(AR) $(T) $(OBJS) 

clean:
	$(RM) $(T) $(OBJS) 


