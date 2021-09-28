#include "wall.h"

void Wall::initWall(){
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
				gameArray[i][j] = '*';
			}
			else {
				gameArray[i][j] = ' ';
			}
		}
	}
}
void Wall::drawWall() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << gameArray[i][j] << ' ';
		}
		if (i == 5) {//显示一些提示，版本信息，操作方法
			cout << "create by hr";
		}
		if (i == 6) {
			cout << "up:w";
		}
		if (i == 7) {
			cout << "down:s";
		}
		if (i == 8) {
			cout << "left:a";
		}
		if (i == 9) {
			cout << "right:d";
		}
		cout << endl;
	}
}

void Wall::setWall(int x, int y, char c)//符号保存，包含整个墙内的所有符号（墙，蛇头，蛇身，食物）
{
	gameArray[x][y] = c;//通过此符号数组可以判断移动的下一个位置是否可行
	//主要判断是* # @
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];//获得次数坐标的符号
}
