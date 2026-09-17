CC=gcc
SRCS:= $(wildcard src/*.c)
TARGET=advanced_interpreter

all: $(TARGET)
clean:
	rm $(TARGET)

advanced_interpreter: $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)
