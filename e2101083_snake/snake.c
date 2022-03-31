#include "snake.h"
#include "screen.h"
#include <stdio.h>
#include <conio.h>
struct snake move(struct snake s, int k) {
	struct snake ns;	//ns new snake
	ns.head = s.head;
	ns.length = s.length;
	if (k == UP) { //this can be repeated for DOWN, RIGHT, LEFT
		ns.head.y--;
	}
	ns.body[0] = s.head; //first body block takes the place/location of the head
	//rest of the body needs a 'for loop'
	for (int i = 1; i < s.length; i++)
		ns.body[i] = s.body[i - 1];
	return ns;
}

//This function returns one of the four arrow key values 
int get_key(void) {
	while (1) {
		int kv = _getch();
		//printf("%d", kv);
		if (kv == 224) { //224 = arrow key
			kv = _getch();
			if (kv == UP || kv == RIGHT || kv == LEFT || kv == DOWN){
				return kv;
		}
		}
	
	}
}

struct snake init_snake(int len) {
	struct snake ls; // ls is a snake structure; used to access data 
					 //elements of "struct snake"
	ls.head.y = INITROW; // rows make up a column
	ls.head.x = INITCOL; //columns make up a row i.e. x row
	ls.length = len;
	for (int i = 0; i < len; i++) {
		ls.body[i].y = INITROW;
		ls.body[i].x = INITCOL - 1 - i; // (-1) initializing growth from left 
										//side of the snake's head & (-i) is so 
										//that the growth keeps happening from the left 
										//side with the value of "i" increasing
	}
	return ls;
}
void draw(struct snake s) {
	clearScreen();
	setBackground(GREEN);
	gotoXY(s.head.x, s.head.y);
	printf(" ");
	setBackground(CYAN);
	for (int i = 0; i < s.length; i++) {
		gotoXY(s.body[i].x, s.body[i].y);
		printf(" ");
	}
	resetColors();
}