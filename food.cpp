#include "food.h"
#include <windows.h>
void gotoxy2(HANDLE h_out2, int x, int y) {//修改光标代码
	COORD pos;
	pos.X = x;//横纵坐标
	pos.Y = y;
	SetConsoleCursorPosition(h_out2, pos);
}
HANDLE h_out2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
Food::Food(Wall& temp_wall) : wall(temp_wall){
	foodX = 0;
	foodY = 0;
}
void Food::setFood()//设置食物的成员函数
{
	while (true) {
		foodX = rand() % (ROW - 2) + 1;//随机
		foodY = rand() % (COL - 2) + 1;
		if (wall.getWall(foodX, foodY) == ' ') {
			wall.setWall(foodX, foodY, 'o');
			gotoxy2(h_out2, foodY * 2, foodX);
			cout << "o";
			break;
		} 
	}
}
