#include <ncurses.h>

#include "draw.h"
#include "../config.h"

void initCurses(int* x, int* y) {

	int maxX;
	int maxY;

	initscr();
	curs_set(0);
	raw();
	keypad(stdscr, TRUE);
	noecho();

	getmaxyx(stdscr, *y, *x);

}

int getKeyLower() {

	int c = getch();

	if (c >= 'A' && c <= 'Z') c += 32;

	return c;
}

void drawStar(int x, int y) {

	mvaddch(y, x, STAR);
	
}
