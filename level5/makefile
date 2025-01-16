
TARGET = hello


CC = g++
CFLAGS = -g -Wall


SRC = hello.cpp


$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

valgrind: $(TARGET)
	valgrind --tool=memcheck ./$(TARGET) this is a test

clean:
	rm -f $(TARGET)

#how to run:
#cd level5
#make
#./hello
