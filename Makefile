CC = gcc
CFLAGS = -w -Wall
TARGET = japangi
OBJECTS = japangi.o manager.o product.o

all : $(OBJECTS)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -I./
clean:
	rm *.o japangi
