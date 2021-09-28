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
		if (i == 5) {//��ʾһЩ��ʾ���汾��Ϣ����������
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

void Wall::setWall(int x, int y, char c)//���ű��棬��������ǽ�ڵ����з��ţ�ǽ����ͷ������ʳ�
{
	gameArray[x][y] = c;//ͨ���˷�����������ж��ƶ�����һ��λ���Ƿ����
	//��Ҫ�ж���* # @
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];//��ô�������ķ���
}
