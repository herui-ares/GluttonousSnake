#ifndef _WALL_HEAD//�����ظ�����,����ļ�include�Ļ��ᵼ���ض���
#define _WALL_HEAD
#include <iostream>
using namespace std;
const int ROW = 26;//���峣����const��Ϊ�߽����
const int COL = 26;//���峣����const��Ϊ�߽����
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
