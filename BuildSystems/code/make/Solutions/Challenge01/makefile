# Includes here

# varaibles here
CC = mingw32-gcc
TARGET = result.exe
LDFLAGS = -L.
CSTD = -std=c99
CFLAGS  = $(CSTD) -Wall 

# Basic Targets 
all: main.o
	$(CC) main.c $(CFLAGS) $(LDFLAGS) -o $(TARGET)

clean:
	rm -rf $(TARGET)

debug:
	$(CC) main.c -g3 $(CFLAGS) $(LDFLAGS) -o $(TARGET)_dgb




