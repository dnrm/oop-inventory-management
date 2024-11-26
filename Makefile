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

all: $(TARGET)

# Compile all .cpp files
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove all the .o files 
clean:
	rm -f $(OBJ) $(TARGET) src/*.o