# Configurações de compilação
GCCFLAGS = -g -Wall -Wfatal-errors --coverage -fsanitize=address,undefined
ALL = main
GCC = gcc 
SRC = src/
EVERYTHING = $(wildcard $(SRC)*.c) Unity/src/unity.c

# Regras principais
all: $(ALL)

$(ALL): main.c $(EVERYTHING)
	$(GCC) $(GCCFLAGS) -o $@ $^ 

# Análise de cobertura de código com gcov
coverage: all
	./$(ALL)  
	gcov $(EVERYTHING) 

# Análise estática com cppcheck
static-analysis:
	cppcheck --enable=all --inconclusive $(EVERYTHING)

# Verificação de memória com valgrind
memcheck:
	valgrind --leak-check=full --track-origins=yes ./$(ALL)

# Sanitizers (detecta erros de memória em tempo de execução)
sanitize:
	./$(ALL)

# Limpeza dos arquivos gerados
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