#------------------------------------------------------------------------------
#Programming Assignment 2 - Breadth First Search and Shortest Paths
#
# make FindPath          makes FindPath
# make GraphClient       makes ListClient
# make clean             removes all binaries
# make checkClient       checks ListClient for memory errors
# make checkFindPath     checks Lex for memory errors
#------------------------------------------------------------------------------

CC      = clang
CFLAGS  = -std=c17 -Wall
LFLAGS  = -lm
EXEC    = FindPath
FindPath_OBJS    = FindPath.o Graph.o List.o
GraphClient_OBJS = GraphClient.o Graph.o List.o
GraphTest_OBJS   = GraphTest.o Graph.o List.o

FindPath: $(FindPath_OBJS)
	$(CC) $(LFLAGS) -o FindPath $(FindPath_OBJS)

GraphClient: $(GraphClient_OBJS)
	$(CC) $(LFLAGS) -o GraphClient $(GraphClient_OBJS)

GraphTest: $(GraphTest_OBJS)
	$(CC) $(LFLAGS) -o GraphTest $(GraphTest_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<


clean :
	rm -f FindPath GraphClient GraphTest FindPath.o Graph.o GraphClient.o GraphTest.o List.o

checkClient :
	valgrind --leak-check=full GraphClient

checkFindPath :
	valgrind --leak-check=full FindPath in3 blah3
