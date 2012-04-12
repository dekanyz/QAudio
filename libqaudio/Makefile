CC = g++
LD = g++
CFLAGS = -g -Wall
LDFLAGS = -ljack 
RM = /bin/rm -f

PROG = libqaudio.so

# Creating a list of object files (a .o file will belong to every .c)
SRC  := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SRC))


# top-level rule, to compile everything.
# all: $(PROG)

# dependency list.

$(PROG): $(OBJS)

	$(LD) $(LDFLAGS) $(OBJS) -o $(PROG)


# Source dependencies
# TODO: Clean these dependencies
BufferPool.o: 		BufferPool.cpp BufferPool.h Buffer.h Jack.h
Jack.o:	      		Jack.cpp Jack.h
# Cli.o:		  		Cli.cpp Cli.h
Messages.o:	  		Messages.cpp Messages.h Configure.h
SingletonBase.o:	SingletonBase.cpp SingletonBase.h
XmlParser.o:		XmlParser.cpp XmlParser.h

# main.o:		  		main.c

# rule for cleaning re-compilable files.
clean:
	$(RM) *.o $(PROG)

.PHONY: clean
