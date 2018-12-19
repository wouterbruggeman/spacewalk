CC=g++
IDIR=include
SRCDIR=src

EXECUTABLE_NAME=spacewalk
LIBS=-lncurses

all:
	$(CC) -I $(IDIR) $(SRCDIR)/* -o $(EXECUTABLE_NAME) $(LIBS)
clean:
	rm *.o $(EXECUTABLE_NAME)
