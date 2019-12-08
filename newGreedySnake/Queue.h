#ifndef QUEUE_H
#define QUEUE_H
#include"Point.h"
#include <vector>
#define AREA_MARGIN 32
class MyQueue{
private:
	std::vector<Point> queue;
	int size;
	int head;
	int tail;
public:
	MyQueue():size(AREA_MARGIN*AREA_MARGIN),head(-1),tail(0){
		queue = std::vector<Point>(size);
	}
	void push(int x, int y){
        if((tail+1)%size == head)   // ∂”¡–¬˙¡À
			return ;
        if(head == -1)
			head++;
		queue[tail] = Point(x,y);
		tail = (tail +1) %size;
	}
	void pop(){
        if(head == tail || head ==-1)
			return ;
		head = (head+1)%size;
	}
	Point getQueueHeadElement(){
		if(head == tail || head == -1)
			return Point(-1,-1);
		return queue[head];
	}
	Point getQueueTailElement(){
		
		return queue[(tail -1 + size)%size];
	}
	std::vector<Point> getData(){
		std::vector<Point> queueData((tail - head + size)%size);
		for(int tempHead = head ,i = 0;tempHead!=tail;tempHead = (tempHead+1)%size){
            queueData[i++] = queue[tempHead];
		}
		return queueData;
	}
};
#endif