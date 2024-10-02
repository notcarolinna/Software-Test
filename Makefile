CFLAGS = -fprofile-arcs -ftest-coverage -g
LDFLAGS = -lgcov

all: app test

# Compila o aplicativo principal
app:
	gcc $(CFLAGS) -o app src/quick_sort.c src/merge_sort.c src/heap_sort.c \
        src/selection_sort.c src/insertion_sort.c src/bubble_sort.c \
        src/radix_sort.c src/counting_sort.c src/sort.c main.c $(LDFLAGS)

# Testes
test:
	gcc $(CFLAGS) -o test_sort src/quick_sort.c src/merge_sort.c src/heap_sort.c \
        src/selection_sort.c src/insertion_sort.c src/bubble_sort.c \
        src/radix_sort.c src/counting_sort.c src/sort.c test_sort.c -I./ $(LDFLAGS)

# Code Coverage
coverage: test_sort
	./test_sort
	gcov src/*.c

# AddressSanitizer 
sanitizer:
	gcc $(CFLAGS) -fsanitize=address -o test_sort src/quick_sort.c src/merge_sort.c \
        src/heap_sort.c src/selection_sort.c src/insertion_sort.c src/bubble_sort.c \
        src/radix_sort.c src/counting_sort.c src/sort.c test_sort.c -I./
	./test_sort

# Limpa 
clean:
	rm -f app test_sort *.gcda *.gcno *.gcov