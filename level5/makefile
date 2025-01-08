# שם הקובץ שייווצר אחרי הקומפילציה
TARGET = hello

# המהדר והדגלים
CC = g++
CFLAGS = -g -Wall

# קבצי המקור
SRC = hello.cpp

# קומפילציה של התוכנית
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# הרצת Valgrind עם Memcheck
valgrind: $(TARGET)
	valgrind --tool=memcheck ./$(TARGET) this is a test

# ניקוי קבצים שנוצרו
clean:
	rm -f $(TARGET)
