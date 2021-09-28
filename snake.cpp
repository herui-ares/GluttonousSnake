#include "snake.h"
#include <windows.h>
HANDLE h_out1 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
void gotoxy1(HANDLE h_out1, int x, int y) {//修改光标代码
	COORD pos;
	pos.X = x;//横纵坐标
	pos.Y = y;
	SetConsoleCursorPosition(h_out1, pos);
}
Snake::Snake(Wall& temp_wall, Food& temp_food) : wall(temp_wall), food(temp_food)
{
	pHead = NULL;
	isRool = false;
}
void Snake::initSnake()
{
	destoryPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}
void Snake::addPoint(int x, int y)//添加节点，在移动时，吃到食物，或者没吃到食物
{
	//创建新节点
	Point* new_point = new Point;
	new_point->x = x;
	new_point->y = y;
	new_point->next = NULL;
	//如果原来的头不为空， 改为等号
	if (pHead != NULL) {
		wall.setWall(pHead->x, pHead->y, '=');
		gotoxy1(h_out1, pHead->y * 2, pHead->x);
		cout << "=";
	}
	new_point->next = pHead;
	pHead = new_point;
	wall.setWall(pHead->x, pHead->y, '@');
	gotoxy1(h_out1, pHead->y * 2, pHead->x);
	cout << "@";
}

void Snake::destoryPoint()
{
	Point* pCur = pHead;
	while (pHead != NULL) {
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::delPoint()
{//可以试试用双向链表删除改进试试
	if (pHead == NULL || pHead->next == NULL) {
		return;
	}
	Point* p_cur = pHead->next;
	Point* p_pre = pHead;
	while (p_cur->next != NULL) {
		p_pre = p_pre->next;
		p_cur = p_cur->next;
	}
	wall.setWall(p_cur->x, p_cur->y, ' ');
	gotoxy1(h_out1, p_cur->y * 2, p_cur->x);
	cout << " ";
	delete p_cur;//删除尾节点
	p_cur = NULL;
	p_pre->next = NULL;
}

bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;
	switch (key) 
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}
	//判断下一步是否碰到尾巴
	Point* p_cur = pHead->next;
	Point* p_pre = pHead;
	while (p_cur->next != NULL) {
		p_pre = p_pre->next;
		p_cur = p_cur->next;
	}
	if (p_cur->x == x && p_cur->y == y) {
		//碰到尾巴
		isRool = true;

	}
	else {
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
			system("cls");
			wall.drawWall();
			cout << "得分：" <<getScore() << "分" << endl;
			cout << "GAME OVER!" << endl;
			return false;
		}
	}
	if (wall.getWall(x, y) == 'o') {//吃到食物
		addPoint(x, y);
		food.setFood();
	}
	else {//未吃到食物
		addPoint(x, y);
		delPoint();
		if (isRool == true) {
			wall.setWall(x, y, '@');
			gotoxy1(h_out1, y * 2, x);
			cout << "@";
		}
	}
	return true;
}

int Snake::getSleepTime()
{
	int sleep_time = 0;
	int size = countList(); 
	if (size < 5) {
		sleep_time = 300;
	}
	else if (size >= 5 && size <= 8) {
		sleep_time = 200;
	}
	else {
		sleep_time = 100;
	}
	return sleep_time;
}

int Snake::countList()
{ 
	int size = 0;
	Point* cur_point = pHead;
	while (cur_point) {
		size++;
		cur_point = cur_point->next;
	}
	return size;
}

int Snake::getScore()
{
	int size = countList();
	int score = (size - 3) * 100;
	return score;
}
