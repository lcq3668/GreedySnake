#include "Snake.h"
Point Snake::move(int direction,const Point& food,bool& eat,bool&flag){
	/*
	返回 蛇头的位置
	*/
	
	int incresmentX, incresmentY;
	if(direction == UP){
		incresmentX = 0;
		incresmentY = -1;
	}
	else if(direction == DOWN){
		incresmentX = 0;
		incresmentY = 1;
	}
	else if(direction == LEFT){
		incresmentX = -1;
		incresmentY = 0;
	}
	else {
		incresmentX = 1;
		incresmentY = 0;
	}
	Point temp = queue.getQueueTailElement();
	int newX = temp.getX()+incresmentX;
	int newY = temp.getY()+incresmentY;
	flag = false;
	if (isBody(Point(newX, newY))) {
		flag = true;
	}
	if(checkFood(newX,newY,food)){
        eat = true;
	}
	else{
		queue.pop();
		eat = false;
	}
	queue.push(newX,newY);
	return Point(newX,newY);
}