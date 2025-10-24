TARGET = finproc

SRC_DIR = src
INC_DIR = include

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:.cpp=.o)

CXX = g++
CXXFLAGS = -std=c++17 -I$(INC_DIR) -Wall -Wextra

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

