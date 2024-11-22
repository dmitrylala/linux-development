.PHONY: clean

CC = gcc
CFLAGS = -Wall -Werror -Wextra -O2 -fsanitize=undefined
GENERATES = generate_maze_v0 generate_maze_v1 generate_maze_v2 generate_maze_v3 *.o *.rej generate_maze_v1.c generate_maze_v2.c generate_maze_v3.c

all: generate_maze_v0 generate_maze_v1 generate_maze_v2 generate_maze_v3
	./generate_maze_v0
	./generate_maze_v1 10
	./generate_maze_v2 .A 10
	./generate_maze_v3 40 .# 10

generate_maze_v1.c:
	patch generate_maze_v0.c -o $@ < v1.patch

generate_maze_v2.c:
	patch generate_maze_v1.c -o $@ < v2.patch

generate_maze_v3.c:
	patch generate_maze_v2.c -o $@ < v3.patch

clean:
	rm -f $(GENERATES)
