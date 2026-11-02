CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic
TARGET = campus_route_finder
SOURCE = main.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all run clean
