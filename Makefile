# internal flags
CCFLAGS     :=
LDFLAGS     :=

# Extra user flags
EXTRA_LDFLAGS     ?=
EXTRA_CCFLAGS     ?=

ALL_CCFLAGS :=
ALL_CCFLAGS += $(addprefix -Xcompiler ,$(CCFLAGS))
ALL_CCFLAGS += $(addprefix -Xcompiler ,$(EXTRA_CCFLAGS))

ALL_LDFLAGS :=
ALL_LDFLAGS += $(ALL_CCFLAGS)
ALL_LDFLAGS += $(addprefix -Xlinker ,$(LDFLAGS))
ALL_LDFLAGS += $(addprefix -Xlinker ,$(EXTRA_LDFLAGS))

GCCFLAGS = -g -Wall -Wfatal-errors 
GCC = gcc
SANITIZER = -fsanitize=address
#CCPCHECKFLAGS = --enable=all --suppress=missingIncludeSystem
GCOVFLAGS = -fprofile-arcs -ftest-coverage

SOURCES = src/sort.c src/bubble_sort.c src/counting_sort.c src/heap_sort.c \
    src/insertion_sort.c src/merge_sort.c src/quick_sort.c src/radix_sort.c \
    src/selection_sort.c main.c
TEST_SOURCES = ./test/all_tests.c ./test/testes.c ./test/Test_Runner.c

EXEC = exec

UNITY_ROOT = Unity
UNITY_SRC=$(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  test/testes.c \
  test/Test_Runner.c \
  test/all_tests.c \
  src/sort.c
UNITY_INC_DIRS = -Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
UNITY_TARGET = all_tests

# Definindo as entradas de teste
INPUT1 = -a counting -n 10 -s random
INPUT2 = -a radix -n 10 -s random
INPUT3 = -a bubble -n 10 -s random
INPUT4 = -a insertion -n 10 -s random
INPUT5 = -a selection -n 10 -s random
INPUT6 = -a heap -n 10 -s random
INPUT7 = -a merge -n 10 -s random
INPUT8 = -a quick -n 10 -s random

.PHONY: clean cppcheck valgrind sanitizer unity coverage

all: clean cppcheck valgrind sanitizer unity coverage
	
#cppcheck: $(SOURCES) $(TEST_SOURCES)
#	cppcheck $(CCPCHECKFLAGS) --error-exitcode=1 $^

valgrind: $(SOURCES)
	$(GCC) $(GCCFLAGS) $(GCOVFLAGS) -o $(EXEC) $^  # Adicionei GCOVFLAGS
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT1)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT2)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT3)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT4)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT5)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT6)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT7)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(INPUT8)

sanitizer: $(SOURCES)
	$(GCC) $(GCCFLAGS) $(SANITIZER) -o $(EXEC) $^
	./$(EXEC) $(INPUT1)
	./$(EXEC) $(INPUT2)
	./$(EXEC) $(INPUT3)
	./$(EXEC) $(INPUT4)
	./$(EXEC) $(INPUT5)
	./$(EXEC) $(INPUT6)
	./$(EXEC) $(INPUT7)
	./$(EXEC) $(INPUT8)

unity:
	$(GCC) $(GCCFLAGS) $(GCOVFLAGS) $(UNITY_INC_DIRS) $(UNITY_SRC) -o $(UNITY_TARGET)  
	./$(UNITY_TARGET) -v
	gcov -b $(SOURCES)  

coverage: $(EXEC)
	gcov $(SOURCES)

app: sort.c main.c 
	$(GCC) sort.c main.c -o $@

clean:
	rm -fr app $(EXEC) $(UNITY_TARGET) *.o cov* *.dSYM *.gcda *.gcno *.gcov
