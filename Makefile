NAME = zverc

SRC = src
BUILD = build
BIN = $(BUILD)/bin
INCLUDE = include

CC = gcc
CFLAGS = -I$(INCLUDE) -Wall -Wextra

TARGET = $(BIN)/$(NAME)
SRCFILES = $(wildcard $(SRC)/*.c)
OBJFILES = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCFILES))


all: $(TARGET)


$(TARGET): $(OBJFILES)
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $^ -o $@


$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(BUILD)
