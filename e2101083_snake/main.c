#include "snake.h"

int main(void) {
	struct snake s = init_snake(5);
	while (1) {
		draw(s);
		//break;
		//get_key() used to move the snake with keys from keyboard
		int k = get_key();
		s = move(s, k); //changes the location of head and body 
						//of the snake acc to where the snake is 

	}
}