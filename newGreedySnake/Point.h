#ifndef POINT_H
#define POINT_H
class Point{
private:
	int x;
	int y;
public:
	Point(int x =-1, int y=-1):x(x),y(y){
        
	}
	Point(const Point& another){
		x = another.getX();
		y = another.getY();
	}
	
public:
	int getX()const{
		return x;
	}
	int getY()const{
		return y;
	}
	void setX(int x){
		this->x = x;
	}
	void setY(int y){
		this->y = y;
	}


};
#endif