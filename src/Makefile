TARGET = s21_containers.a
CC = g++ -std=c++17 -g
CPPFLAGS = -Wall -Werror -Wextra 
TESTFLAGS = -lgtest -pthread
# LINUX_FLAGS = -lrt -lpthread -lm -lsubunit
GCOV_FLAGS = --coverage #-fprofile-arcs -ftest-coverage 
TEST_SRC = tests/*.cc
TEST_TARGET = test

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: test

clean:
	@rm -rf *.o *.a *.out *.log $(TEST_TARGET)
	@rm -rf *.gc* *.info *.dSYM gcov_report report

test: clean
ifeq ($(OS), Darwin)
	@$(CC) $(TESTFLAGS) $(CPPFLAGS) $(TEST_SRC) -o $(TEST_TARGET)
else
	@$(CC) $(TESTFLAGS) $(TEST_SRC) $(CPPFLAGS) -o $(TEST_TARGET) $(LINUX_FLAGS)
endif
	@./$(TEST_TARGET)

gcov_report: clean
	@$(CC) $(TESTFLAGS) $(GCOV_FLAGS) $(CPPFLAGS) $(TEST_SRC) -o gcov_report 
	@./gcov_report
	@lcov -t "stest" --no-external --ignore-errors mismatch -o test.info -c -d  .
	@genhtml -o report test.info
	@open ./report/index.html
	@rm -rf *.gc*

leaks: clean test
	@leaks --atExit -- ./$(TEST_TARGET)

valgrind: clean
	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --log-file="valgrind.log" -v --verbose -q --quiet -s ./$(TEST_TARGET)

clang:
	@clang-format -i --style=Google */*.h */*.cc

style:
	@clang-format -n --style=Google */*.h */*.cc

# main:
# 	$(CC) $(FLAGS) main.cc
# 	./a.out
