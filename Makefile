GCCFLAGS = -g -Wall -Wfatal-errors
ALL = identifier
GCC = gcc 
SRC = src/
EVERYTHING = src/sort.c src/bubble_sort.c src/counting_sort.c src/heap_sort.c \
	src/insertion_sort.c src/merge_sort.c src/quick_sort.c src/radix_sort.c \
	src/selection_sort.c 

all: $(ALL)

identifier: identifier.c 
	$(GCC) $(GCCFLAGS) -o $@ $< $(EVERYTHING)

clean:
	rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov

# Ferramentas de Descrição de Testes:
# gtest, cpptest, catch, fuzzy testing
# Code Coverage:
# gcov, cppcheck, valgrind, sanitizer
# Comandos:
# gcc: gcc test.c
# cppcheck: cppcheck --enable=all --suppress=missingIncludeSystem test.c
# valgrind: gcc -g -Wall -Wfatal-errors test.c -o test
          # valgrind --leak-check=full --show-leak-kinds=all ./test
# address sanitizer: gcc -g -Wall -Wfatal-errors -fsanitize=address test.c -o test ./test