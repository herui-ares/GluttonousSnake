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
		//数据域
		int x;
		int y;

		//指针域
		Point* next;
	};

	void initSnake();//初始化
	void addPoint(int x, int y);//添加
	void destoryPoint();//销毁节点，初始化
	void delPoint();

	bool move(char key);

	//设定难度
	int getSleepTime(); 
	int countList();
	int getScore();

	bool isRool;

	Point* pHead;//链表存储蛇的身子及头部信息
	Wall& wall;
	Food& food;
};
