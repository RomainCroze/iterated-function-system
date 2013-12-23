CC=g++
CFLAGS=-Wall -std=c++0x
LDFLAGS=
EXEC=sierpinski dragon
LIBS=-lX11 -ljpeg -lpthread

all: $(EXEC)

sierpinski: IFS.o sierpinski.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

dragon: IFS.o dragon.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

IFS.o: IFS.h

dragon.o: IFS.h dragon.h

sierpinski.o: IFS.h sierpinski.h

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)