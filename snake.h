#pragma once
#include <iostream> 
#include "wall.h"
#include "food.h"
using namespace std;
class Snake {
public:
	Snake(Wall& temp_wall, Food& temp_food);

	enum {UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };
	struct Point {
		//������
		int x;
		int y;

		//ָ����
		Point* next;
	};

	void initSnake();//��ʼ��
	void addPoint(int x, int y);//���
	void destoryPoint();//���ٽڵ㣬��ʼ��
	void delPoint();

	bool move(char key);

	//�趨�Ѷ�
	int getSleepTime(); 
	int countList();
	int getScore();

	bool isRool;

	Point* pHead;//����洢�ߵ����Ӽ�ͷ����Ϣ
	Wall& wall;
	Food& food;
};
