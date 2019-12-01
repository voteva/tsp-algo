CC=gcc
CFLAGS=-Wall -Werror -ggdb3 -D_POSIX_C_SOURCE -std=c99
INC=-Iinclude

OBJ_DIR=obj
BIN_DIR=.
SOURCES=$(wildcard src/*.c)
SOURCES_TEST=$(SOURCES) test/test.c
OBJECTS=$(SOURCES:.c=.o)
OBJECTS_TEST=$(SOURCES_TEST:.c=.o)
MAIN_OBJECTS=$(filter-out $(OBJ_DIR)/test.o, $(wildcard $(OBJ_DIR)/*.o))
TEST_OBJECTS=$(OBJ_DIR)/pattern.o $(OBJ_DIR)/test.o
TARGET=tsp

.PHONY: all
all: algo

.PHONY: algo
algo: mkdir $(OBJECTS)
	$(CC) $(MAIN_OBJECTS) $(LIB) -o $(BIN_DIR)/$(TARGET)

.c.o:
	$(CC) -c $(CFLAGS) $(INC) $< -o $(OBJ_DIR)/$(notdir $@)

.PHONY: mkdir
mkdir:
	mkdir -p ./$(OBJ_DIR)
	mkdir -p ./$(BIN_DIR)

.PHONY: clean
clean:
	rm -f proto/*.c proto/*.h
	rm -rf $(OBJ_DIR)*
	rm -rf $(BIN_DIR)*