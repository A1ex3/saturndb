CC = clang
SRC_DIR = ./src
LIB_NAME = saturndb
BUILD_DIR = build

ifeq ($(OS),Windows_NT)
	CFLAGS = -O3
	LIB_EXT = .dll
else
	CFLAGS = -Wall -Werror -fpic
	LIB_EXT = .o
endif

create_build_dir:
ifeq ($(OS),Windows_NT)
	mkdir $(BUILD_DIR)
else
	mkdir -p $(BUILD_DIR)
endif

build: create_build_dir $(SRC_DIR)/*.c
	$(CC) -shared -o $(BUILD_DIR)/$(LIB_NAME)$(LIB_EXT) $(filter-out create_build_dir,$^) $(CFLAGS)