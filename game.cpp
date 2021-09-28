#include <iostream>
using namespace std;
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <conio.h>
#include <windows.h>
void gotoxy(HANDLE h_out, int x, int y) {//修改光标代码
    COORD pos;
    pos.X = x;//横纵坐标
    pos.Y = y;
    SetConsoleCursorPosition(h_out, pos);
}
HANDLE h_out = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
int main()
{
    srand((unsigned int)time(NULL));//添加随机种子，
    //rand其实是机器内部设置一段随机数，再通过余法随机计算，因此每次程序运行求得的随机数其实是一样的
    //通过srand初始化随机种子，来每次获得不一样的随机数
    bool is_dead = false;
    char pre_key = NULL;
    Wall wall;
    wall.initWall();//初始化墙壁
    wall.drawWall();//显示墙壁

    Food food(wall);
    food.setFood();

    Snake snake(wall, food);
    snake.initSnake();

    gotoxy(h_out, 0, ROW);
    cout << "得分：" << snake.getScore() << "分" << endl;
    //gotoxy(h_out, 10, 5); //y*2 x

        while (!is_dead) {
            char key = _getch();
            //判断起始按键按左
            if(pre_key == NULL && key == snake.LEFT) {
                continue;
            }
            
            do {
                if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) {

                    //判断冲突按键，
                    if ((key == snake.LEFT && pre_key == snake.RIGHT) ||
                        (key == snake.RIGHT && pre_key == snake.LEFT) ||
                        (key == snake.UP && pre_key == snake.DOWN) ||
                        (key == snake.DOWN && pre_key == snake.UP)) {
                        key = pre_key;
                    }
                    else {
                        pre_key = key;//不是冲突按键
                    }
                    if (snake.move(key) == true) {
                        gotoxy(h_out, 0, ROW);
                        cout << "得分：" << snake.getScore() << "分" << endl;
                        Sleep(snake.getSleepTime());
                    }
                    else {
                        is_dead = true;
                        break;
                    }
                }
                else {
                    key = pre_key;
                }
            } while (!_kbhit());
            
            if (snake.move(key) == true) {
                Sleep(300);
            }
            else {
                is_dead = true;
                break;
            }
    }
}

