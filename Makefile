all: src/main.c src/vectors/vectors.c
	cc src/main.c src/vectors/vectors.c src/vectors/matrix.c src/vectors/randvec.c src/draw/draw.c -o cursed-stars -lncurses -lm
