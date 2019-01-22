CC=g++
IDIR=include
SRCDIR=src

EXECUTABLE_NAME=spacewalk
LIBS=-lncurses

all:
	$(CC) -I $(IDIR) $(SRCDIR)/* -o $(EXECUTABLE_NAME) $(LIBS)
debug:
	reset
	$(CC) -I $(IDIR) $(SRCDIR)/* -o $(EXECUTABLE_NAME) $(LIBS) -g
	gdb -q ./$(EXECUTABLE_NAME)
run:
	$(CC) -I $(IDIR) $(SRCDIR)/* -o $(EXECUTABLE_NAME) $(LIBS)
	./$(EXECUTABLE_NAME)

clean:
	rm *.o $(EXECUTABLE_NAME)
