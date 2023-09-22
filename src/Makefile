# TARGET = s21_containers.a
# CC = g++ -std=c++17 -g
# CPPFLAGS = -Wall -Werror -Wextra 
# TESTFLAGS = -lgtest -pthread
# LINUX_FLAGS = -lrt -lpthread -lm -lsubunit
# GCOV_FLAGS = --coverage #-fprofile-arcs -ftest-coverage 
# TEST_SRC = tests/*.cc
# TEST_TARGET = test

# ifeq ($(OS),Linux)
#   OPEN_CMD = xdg-open
# endif
# ifeq ($(OS),Darwin)
# 	OPEN_CMD = open
# endif

# all: test

# clean:
# 	@rm -rf *.o *.a *.out *.log $(TEST_TARGET)
# 	@rm -rf *.gc* *.info *.dSYM gcov_report report

# test: clean
# ifeq ($(OS), Darwin)
# 	@$(CC) $(TESTFLAGS) $(CPPFLAGS) $(TEST_SRC) -o $(TEST_TARGET)
# else
# 	@$(CC) $(TESTFLAGS) $(TEST_SRC) $(CPPFLAGS) -o $(TEST_TARGET) $(LINUX_FLAGS)
# endif
# 	@./$(TEST_TARGET)

# gcov_report: clean
# 	@$(CC) $(TESTFLAGS) $(GCOV_FLAGS) $(CPPFLAGS) $(TEST_SRC) -o gcov_report 
# 	@./gcov_report
# 	@lcov -t "stest" --no-external --ignore-errors mismatch -o test.info -c -d  .
# 	@genhtml -o report test.info
# 	@open ./report/index.html
# 	@rm -rf *.gc*

# leaks: clean test
# 	@leaks --atExit -- ./$(TEST_TARGET)

# valgrind: clean
# 	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
# 	--show-leak-kinds=all --track-origins=yes --log-file="valgrind.log" -v --verbose -q --quiet -s ./$(TEST_TARGET)

# clang:
# 	@clang-format -i --style=Google */*.h */*.cc

# style:
# 	@clang-format -n --style=Google */*.h */*.cc

# # main:
# # 	$(CC) $(FLAGS) main.cc
# # 	./a.out

CC = g++ -std=c++17 -g
CPPFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = --coverage
CLEAN	= rm -rf

OC := $(shell uname)
ifeq ($(OC),Darwin)
	LEAKS = CK_FORK=no leaks --atExit --
	TESTFLAGS = -lgtest -lgtest_main -lm -lstdc++ $(shell pkg-config --cflags gtest)
else
	LEAKS = valgrind --leak-check=full --track-origins=yes -s
	TESTFLAGS = -lgtest -lgtest_main -lm -lstdc++ -lpthread $(shell pkg-config --cflags gtest)
endif

NAME = Containers

SRC_DIR					= ./array/* ./list/* ./queue/* ./stack/* ./vector/*
# SOURCE_FILES			= *.cc

TEST_FILE				= $(NAME)_test
TEST_FILE_COV			= $(TEST_FILE)_cov

TEST_DIR				= ./tests
TEST_SOURCE_FILE		= *.cc

# SOURCE					= $(SRC_DIR)/$(SOURCE_FILES) 
TEST 					= $(TEST_DIR)/$(TEST_SOURCE_FILE)

all: clean test

clean:
	$(CLEAN) $(TEST_FILE) $(TEST_FILE_FOR_LEAKS) $(TEST_FILE_COV) .clang-format
	$(CLEAN) *.o *.a *.gcno *.gcda *.info *.out *.gch *.dSYM report
	$(CLEAN) ../$(DIST_NAME).tar.gz ../$(DIST_NAME)
	$(CLEAN) ../documentation
	$(CLEAN) report*

$(TEST_FILE): $(SOURCE) $(TEST)
	$(CC) $(CPPFLAGS) $(SOURCE) $(TEST) -o $(TEST_FILE) $(TESTFLAGS)

test: $(TEST_FILE)
	./$(TEST_FILE)

report/index.html: $(SOURCE) $(TEST)
	$(CC) $(CPPFLAGS) $(GCOVFLAGS) $(SOURCE) $(TEST) -o $(TEST_FILE_COV) $(TESTFLAGS)
	./$(TEST_FILE_COV)
	lcov -t "$(TEST_FILE_COV)" -o $(TEST_FILE_COV).info -c -d . --no-external
	genhtml -o report $(TEST_FILE_COV).info

gcov_report: report/index.html
	open report/index.html

open_report:
	-$(OPEN) report/index.html

check: leaks cppcheck linter

linter:
	@cp ../linters/.clang-format ./
	@clang-format -n $(TEST)
	@clang-format -n $(SOURCE)
	@clang-format -n view/*/*.cc view/*/*.h
	@clang-format -n controller/*.cc controller/*.h
	@clang-format -n main.cc
	@rm -f .clang-format

run_linter:
	@cp ../linters/.clang-format ./
	@clang-format -i $(TEST)
	@clang-format -i $(SOURCE)
	@clang-format -i view/*/*.cc view/*/*.h
	@clang-format -i controller/*.cc controller/*.h
	@clang-format -i main.cc
	@rm -f .clang-format

cppcheck:
	cppcheck --std=c++17 --enable=all --language=c++ --suppress=missingIncludeSystem $(TEST) $(SOURCE)

leaks: $(TEST_FILE)
	$(LEAKS) ./$(TEST_FILE)

.PHONY: all clean test gcov_report rebuild linter cppcheck leaks check