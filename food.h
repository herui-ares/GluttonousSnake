#pragma once //����ͬһ�ļ���include���
#include <iostream>
#include "wall.h"

using namespace std;
class Food {
public:
	Food(Wall& temp_wall);
	void setFood();
	int foodX;
	int foodY;

	Wall& wall; //���������ó�Ա�����ó�Ա�Ļ�����ʹ���б��ʼ������������ָ���Ա
};