#pragma once
// In header file we usually have 3 sections;
// constant definition, structure definition & function declaration
#define MAXLEN 50 // constant definition
enum COORD{INITROW=13, INITCOL=40};
enum ARROW{UP=72, LEFT=75, RIGHT=77, DOWN=80};
//structure definition :-
struct coord {
	int x, y; // type of data; data elements of the structure
}; 

struct snake {
	struct coord head;
	struct coord body[MAXLEN];
	int length;
};

//function declarations :-
struct snake init_snake(int len); // len is now here the initial length of the snake
void draw(struct snake s);
int get_key(void);
struct snake move(struct snake, int);

/*
3 functions required : 
while(!Dead){ //we can keep while(1) as well since we didn't declare "Dead" yet
	draw()
	move() 
	key()
	}
*/