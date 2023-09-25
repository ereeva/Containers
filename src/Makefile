CC = g++ -std=c++17 -g
CPPFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = --coverage
CLEAN	= rm -rf

OC := $(shell uname)
ifeq ($(OC),Darwin)
	LEAKS = CK_FORK=no leaks --atExit --
	TESTFLAGS = -lgtest -lgtest_main -lm -lstdc++ 
else
	LEAKS = valgrind --leak-check=full --track-origins=yes -s
	TESTFLAGS = -lgtest -lgtest_main -lm -lstdc++ -lpthread $(shell pkg-config --cflags gtest)
endif

NAME = s21_containers

SRC_DIR	= ./array/* ./list/* ./queue/* ./stack/* ./vector/* ./map/* ./set/* ./multiset/*

TEST_FILE	= $(NAME)_test
TEST_FILE_COV	= $(TEST_FILE)_cov
TEST_DIR				= ./tests
TEST_SOURCE_FILE		= *.cc
TEST = $(TEST_DIR)/$(TEST_SOURCE_FILE)

all: clean test

clean:
	$(CLEAN) $(TEST_FILE) $(TEST_FILE_FOR_LEAKS) $(TEST_FILE_COV) .clang-format
	$(CLEAN) *.o *.a *.gcno *.gcda *.info *.out *.gch *.dSYM report
	$(CLEAN) report*

$(TEST_FILE): $(SOURCE) $(TEST)
	$(CC) $(CPPFLAGS) $(SOURCE) $(TEST) -o $(TEST_FILE) $(TESTFLAGS)

test: $(TEST_FILE)
	./$(TEST_FILE)

report/index.html: $(SOURCE) $(TEST)
	$(CC) $(CPPFLAGS) $(GCOVFLAGS) $(SOURCE) $(TEST) -o $(TEST_FILE_COV) $(TESTFLAGS)
	./$(TEST_FILE_COV)
	lcov -t "$(TEST_FILE_COV)" -o $(TEST_FILE_COV).info -c -d . --no-external  --ignore-errors mismatch
	genhtml -o report $(TEST_FILE_COV).info

gcov_report: report/index.html
	open report/index.html

open_report:
	-$(OPEN) report/index.html

check: leaks style

clang:
	clang-format -i --style=Google */*.cc */*.h *.h

style:
	clang-format -n --style=Google */*.cc */*.h *.h

cppcheck:
	cppcheck --std=c++17 --enable=all --language=c++ --suppress=missingIncludeSystem $(TEST) $(SOURCE)

leaks: $(TEST_FILE)
	$(LEAKS) ./$(TEST_FILE)

.PHONY: all clean test gcov_report style cppcheck leaks check