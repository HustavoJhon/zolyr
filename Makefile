# Makefile simple para compilar FINPROC
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
SRC = src
OBJ = obj
BIN = bin
SOURCES = $(wildcard $(SRC)/*.cpp)
TARGET = finproc

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)
	@echo "Compilado: ./$(TARGET)"

clean:
	rm -f $(TARGET)

