# TARGET = s21_containers.a
# CC = gcc
# FLAGS = -Wall -Werror -Wextra -std=c++17 -lstdc++
# TEST_FLAGS = -lgtest -pthread

# all: clang main

# test: clean
# 	$(CC) $(FLAGS) tests/*.cc $(TEST_FLAGS) -o test
# 	./test

# clean:
# 	rm -rf *.o *.a *.out *.log test

# main:
# 	$(CC) $(FLAGS) main.cc
# 	./a.out
	
# clang:
# 	clang-format -i --style=Google */*.h */*.cc *.cc

# /* created by Brilliance Storage Containers(BPA free) Team // sheritsh, bradamar, oznakban, melodiea ※ School 21, Kzn, 2023 */

TARGET = s21_containers.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c++20 -lstdc++
TEST_FLAGS = -lgtest -pthread
TEST_TARGET = test

all: test

clean:
	@rm -rf *.o *.a *.out *.log $(TEST_TARGET)

test: clean
	@$(CC) $(CFLAGS) tests/*.cc $(TEST_FLAGS) -o $(TEST_TARGET)
	./$(TEST_TARGET)

leaks: clean
	@$(CC) $(CFLAGS) tests/*.cc $(TEST_FLAGS) -o $(TEST_TARGET)
	leaks --atExit -- ./$(TEST_TARGET)

valgrind: clean
	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --log-file="valgrind.log" -v --verbose -q --quiet -s ./$(TEST_TARGET)
