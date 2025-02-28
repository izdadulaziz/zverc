
TARGET = zverc

CC = g++

SRC_DIR = src/
BUILD_DIR = build/
BIN_DIR = bin/
INCLUDE_DIR = include/

$(BIN_DIR)$(TARGET) : $(BUILD_DIR)main.o $(BUILD_DIR)zverc.o
	$(CC) $^ -o $@

$(BUILD_DIR)main.o : $(SRC_DIR)main.cpp $(INCLUDE_DIR)zverc.h
	$(CC) -Iinclude -c $< -o $@

$(BUILD_DIR)zverc.o : $(SRC_DIR)zverc.cpp $(INCLUDE_DIR)zverc.h
	$(CC) -Iinclude -c $< -o $@

clean : 
	rm -f $(BIN_DIR)zverc $(BUILD_DIR)zverc.o  $(BUILD_DIR)main.o
