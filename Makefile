CC = clang
CFLAGS = -pthread -Wall -Werror -fpic
SRC_DIR = ./src
LIB_NAME = saturndb.so

lib:
	$(CC) -shared -o ./saturndb.so $(SRC_DIR)/*.c  $(CFLAGS)
