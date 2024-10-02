CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRCS = app/main.c src/sort.c src/bubble_sort.c src/counting_sort.c src/heap_sort.c \
       src/insertion_sort.c src/merge_sort.c src/quick_sort.c src/radix_sort.c \
       src/selection_sort.c
OBJS = $(SRCS:.c=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^

clean:
    rm -f $(OBJS) $(EXEC)
