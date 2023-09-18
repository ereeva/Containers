OS := $(shell uname)

ifeq ($(OS),Darwin) # Mac OS X
    INSTALL_CMD := brew install cmake
else ifeq ($(OS),Linux) # Linux
    INSTALL_CMD := sudo apt-get install cmake
else ifeq ($(OS),Windows_NT) # Windows
    INSTALL_CMD := choco install cmake
else
    $(error Unsupported operating system: $(OS))
endif

PROJECT= s21_containers
VALGRIND_FLAGS= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med

all: test

install:
	$(INSTALL_CMD)

build:
	cmake -B build
	make -C build $(PROJECT)

test: build
	./build/$(PROJECT)

gcov_report: test
	mkdir -p coverage
	lcov -t $(PROJECT) -o coverage/coverage.info -c -d .
	genhtml -o coverage coverage/coverage.info
	open coverage/index.html

valgrind: build
	valgrind $(VALGRIND_FLAGS) ./build/$(PROJECT)
	! grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"

clean:
	rm -rf build
	rm -rf coverage
	if (test -f ./valgrind.txt); then (rm valgrind.txt) fi

clang:
	clang-format --style=google -i tree/*
	clang-format --style=google -i list/*
	clang-format --style=google -i map/*
	clang-format --style=google -i queue/*
	clang-format --style=google -i set/*
	clang-format --style=google -i stack/*
	clang-format --style=google -i vector/*
	clang-format --style=google -i array/*
	clang-format --style=google -i multiset/*
	clang-format --style=google -i tests/*

.PHONY: all test clean