#ifndef _WALL_HEAD//避免重复编译,多个文件include的话会导致重定义
#define _WALL_HEAD
#include <iostream>
using namespace std;
const int ROW = 26;//定义常变量const作为边界的行
const int COL = 26;//定义常变量const作为边界的列
class Wall {
public:
	void initWall();
	void drawWall();
	void setWall(int x, int y, char c);
	char getWall(int x, int y);
private:
	char gameArray[ROW][COL];
};
#endif
