#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Screen.h"
class Game{
private:
	Snake snake;
	Screen *screen;
	
public:
	Game() :snake(Snake()), screen(Screen::getInstance()) {
	}
	void start();
	void endGame(){
		COORD position = {0,AREA_MARGIN2+2};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
		printf("failed to draw");
        exit(0);
	};
	
	Point genFood();
};
#endif