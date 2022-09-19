CC = clang++-7
FLAGS  = -g -Wall -pthread -std=c++17 -O3
SANITIZER = -fsanitize=address -fno-omit-frame-pointer

TARGET = main
SOLUTION = student_code_3.h

all: $(TARGET)

$(TARGET): $(TARGET).cpp $(SOLUTION); \
$(CC) $(TARGET).cpp $(FLAGS) $(SANITIZER) -o $(TARGET)

clean:;\
$(RM) $(TARGET) 