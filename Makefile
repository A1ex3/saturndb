CC = clang
CFLAGS-linux = -Wall -Werror -O3
CFLAGS-win = -O3
SRC_DIR = ./src
LIB_NAME = saturndb

lib-linux:
	$(CC) -shared -o ./build/$(LIB_NAME).o $(SRC_DIR)/*.c  $(CFLAGS-linux)

lib-win:
	$(CC) -shared -o ./build/$(LIB_NAME).dll $(SRC_DIR)/*.c $(CFLAGS-win)