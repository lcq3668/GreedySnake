#include "Game.h"
#include <conio.h>
#include <time.h>
void Game::start(){
	screen->drawMargin();
	// 画蛇的身体
	std::vector<Point> body= snake.getBody();
	for(unsigned int i = 0;i<body.size();i++){
		screen->draw(body[i].getX(),body[i].getY());  
	}
	// 画食物
    Point food(-1,-1);
	srand((unsigned)time(NULL));
    int direction = DOWN;
	bool eat = true;
	bool flag;
	while(true){
		if(eat){
			food = genFood();
			eat = false;
		}
		screen->draw(food.getX(),food.getY());
		Sleep(200);
		if(_kbhit()){
			
			unsigned  key1 = _getch();
			if(key1 == 224){
				unsigned key2 = _getch();
				if(key2 == 72)
				    direction = UP;
				else if(key2 == 80)
				    direction = DOWN;
				else if(key2 == 75)
					direction = LEFT;
				else if(key2 == 77)
					direction = RIGHT;
			}
		}
		Point snakeTail = snake.getTail();
		Point nextPoint = snake.move(direction,food,eat,flag);
		if (flag)
			endGame();
		body = snake.getHeadTail();
		screen->clear(snakeTail);
		for(unsigned int i = 0;i<body.size();i++){
			bool result = screen->draw(body[i].getX(),body[i].getY());
			if(!result){                 
				endGame();
			}
		}	
	}
}

Point Game::genFood(){
	Point food(-1,-1);
	while(true){
		int x = (int)(AREA_MARGIN2*rand()/(RAND_MAX+1.0))+1;
		int y = (int)(AREA_MARGIN2*rand()/(RAND_MAX+1.0))+1;
		food.setX(x);
		food.setY(y);
		if(!snake.isBody(food)){
			break;
		}
	}
	return food;
}