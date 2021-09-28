#pragma once //避免同一文件被include多次
#include <iostream>
#include "wall.h"

using namespace std;
class Food {
public:
	Food(Wall& temp_wall);
	void setFood();
	int foodX;
	int foodY;

	Wall& wall; //可以是引用成员（引用成员的话必须使用列表初始化），或者是指针成员
};