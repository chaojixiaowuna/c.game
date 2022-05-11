#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"
void menu()
{
printf("*******************");
printf("*1.play 0.exit****");
printf("*******************\n");
}
void game()
{
	char ret;
	
	//创建一个二维数组 三行三列存储每一步棋的位置
	char board[row][col]={0};//在.h文件中更改 row col 的值 即可改变数组的行列
	//打印出空棋盘 然后再打印棋子
	InitBoard(board,row,col);//初始化棋盘
	//打印棋盘
	Displayboard(board,row,col);
  /*
  |   |
__|___|__
  |   |
__|___|__
  |   |
  */
	//下棋
	while(1)
	{
    //玩家下棋
	playermove(board,row,col);
	Displayboard(board,row,col);
	//判断玩家是否胜利
	ret=iswin(board,row,col);
		if(ret!='d')
			break;
	//电脑下棋
	PCmove(board,row,col);
	Displayboard(board,row,col);
	//判断电脑是否胜利
	ret=iswin(board,row,col);
	if(ret!='d')
		break;
	}
	if(ret=='*')
		printf("玩家胜利");
	else if(ret=='#')
	printf("电脑胜利");
	else
		printf("平局");
}
void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入指令\n");
		scanf("%d",&input);
		switch(input)
		{
         case 1:
			printf("三子棋游戏开始\n");
			game();
			break;
        case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("指令输入错误，请重新输入指令\n");
				break;
		}
	}
		while(input);
}
int main()
{
	test();
	return 0;
}