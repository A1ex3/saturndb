CC = clang
CFLAGS = -pthread -Wall -Werror -fpic
SRC_DIR = ./src
BUILD_DIR = ./build
LIB_NAME = saturndb.so

lib:
	$(CC) -shared -o $(BUILD_DIR)/saturndb.so $(SRC_DIR)/*.c  $(CFLAGS)
