#pragma once
enum COLOR { BLACK = 30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

void clearScreen(void);
void setBackground(int);
void resetColors(void);
void gotoXY(int, int);