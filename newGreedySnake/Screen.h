#ifndef SCREEN_H
#define SCREEN_H
#define AREA_MARGIN2 32
#include<Windows.h>
class Screen{
private:
	Screen() {

	}
public:
	static Screen* getInstance() { static Screen one; return &one; }
	/*
	bool putFood(int x, int y){
		draw(x,y);
		return true;
	}
	*/
	/*
	void occupy(int x, int y){                // 占领这个位置
        ground[x * AREA_MARGIN2 + y] = true;
	}
    */
	void clear(const Point& p){
		if (isBeyond(p.getX(), p.getY()))
			return ;
		static COORD position;
		position.X = p.getX();
		position.Y = p.getY();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		printf(" ");
		  
	}
	/*
	bool isOccupied(int x, int y){
		return ground[x * AREA_MARGIN2 + y];
	}
	*/
	bool isBeyond(int x, int y){
		if(x <= 0 || x == AREA_MARGIN2+1 || y <= 0 || y == AREA_MARGIN2+1)
			return true;
		else
			return false;
	}
	void drawAfterCheck(int x, int y) {
		static COORD position;
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		printf("@");
	}
	bool draw(int x, int y){
		if(isBeyond(x,y))
			return false;
		else {
			drawAfterCheck(x, y);
			return true;
		}
	}
	void drawMargin() {
		int i = 0; 
		for (int j = 0; j < AREA_MARGIN2 + 2; j++) {
			drawAfterCheck(j, i);
			drawAfterCheck(i, j);
		}

		i = AREA_MARGIN2 +1;
		for (int j = 0; j < AREA_MARGIN2 + 2; j++) {
			drawAfterCheck(j, i);
			drawAfterCheck(i, j);
		}
		
	}
};
#endif