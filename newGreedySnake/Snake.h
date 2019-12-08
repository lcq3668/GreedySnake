#ifndef SNAKE_H
#define SNAKE_H
#include "Queue.h"
#include<vector>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
class Snake{
private:
	MyQueue queue;             
public:
	Snake():queue(MyQueue()){
		queue.push(15,15);
		queue.push(15,16);
		queue.push(16, 16);
	}
	Point move(int direction,const Point& food,bool& eat,bool& flag);
	bool checkFood(int x, int y,const Point& food){                        // 检查是否有食物
		if(x == food.getX() && y == food.getY())
			return true;
		else
			return false;
	}
	// 需要添加的 方法是 1.是否蛇身的一部分 2.返回蛇身
	bool isBody(const Point& tempNode){
		std::vector<Point> body = getBody();
		for(unsigned int i = 0;i<body.size();i++){
			if(body[i].getX() ==tempNode.getX() && body[i].getY() == tempNode.getY()){
				return true;
			}
		}
		return false;
	}

	std::vector<Point> getBody(){
	    return queue.getData();
	}

	Point getTail() {
		return queue.getQueueHeadElement();
	}
	Point getHead() {
		return queue.getQueueTailElement();
	}
	std::vector<Point> getHeadTail() {
		std::vector<Point> headTail;
		headTail.emplace_back(getTail());
		headTail.emplace_back(getHead());
		return headTail;
	}

};
#endif