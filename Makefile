# Generated using GPT-4o
# Commented by me Daniel Medina

# Setup command using G++ compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS =

# Select all .cpp source files 
SRC = main.cpp src/category.cpp src/inventory.cpp src/product.cpp src/supplier.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = main

# Test source files
TEST_SRC = test.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_TARGET = test

all: $(TARGET)

# Compile all .cpp files
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# This is the test target @githubbbbb!!!!
# Compile and run tests
test: $(TEST_OBJ) src/category.o src/inventory.o src/product.o src/supplier.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ) src/category.o src/inventory.o src/product.o src/supplier.o $(LDFLAGS)
	./$(TEST_TARGET)

# Remove all the .o files 
clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) $(TEST_TARGET)