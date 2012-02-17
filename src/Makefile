CC = g++
LD = g++
CFLAGS = -g -Wall
LDFLAGS = -ljack 
RM = /bin/rm -f

PROG = qaudio

# Creating a list of object files (a .o file will belong to every .c)
SRC  := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SRC))


# top-level rule, to compile everything.
# all: $(PROG)

# dependency list.

$(PROG): $(OBJS)

	$(LD) $(LDFLAGS) $(OBJS) -o $(PROG)


# Source dependencies
BufferPool.o: BufferPool.c BufferPool.h Buffer.h
Jack.o:	      Jack.c Jack.h
Cli.o:		  Cli.c Cli.h
Messages.o:	  Configure.h
main.o:		  main.c

# rule for cleaning re-compilable files.
clean:
	$(RM) *.o $(PROG)

.PHONY: clean
