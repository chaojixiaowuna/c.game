#include<stdio.h>
#include<stdlib.h>
#include"game.h"
void InitBoard(char board[row][col],int ROW,int COL )
{
	int i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			board[i][j]=' ';
		}
	}
}
void Displayboard(char board[row][col],int ROW,int COL)
{
	int i,j;

	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
		
		if(j>=COL-1)
			printf(" %c ",board[i][j]);
		else
		printf(" %c |",board[i][j]);//打印一行数据
		
		}
		printf("\n");
		if(i<ROW-1)
		{
		for(j=0;j<COL;j++)
		{
		if(j>=COL-1)
			printf("___");
		else
			printf("___|");//打印一行分隔符
		}
		}
		printf("\n");
	}

}
void playermove(char board[row][col],int ROW,int COL)
{
	int x=0;
	int y=0;
	printf("玩家移动\n");
	while(1)
	{
	printf("请输入所下棋子的坐标：\n");
	scanf("%d %d",&x,&y);
	if(x>=1&&x<=row&&y>=1&&y<=col)
	{
		if(board[x-1][y-1]==' ')
		{
			board[x-1][y-1]='*';
			break;
		}
		else
		printf("该地放已有棋子，请重新下\n");
	}
	else
		printf("棋子下错位置，请重新下：\n");
	}
}
void PCmove(char board[row][col],int ROW,int COL)
{
	int x=0;
	int y=0;
	printf("电脑走\n");
	while(1)
	{
	x=rand()%row;
	y=rand()%col; 
	if(board[x][y]==' ')
	{
		board[x][y]='#';
		break;
	}
	}
}
int isfull(char board[row][col],int ROW,int COL)
{
	int i;
	int j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(board[i][j]==' ')
			{
				return 0;
				break;
			}
		}
	}
	return 1;
}
char iswin(char board[row][col],int ROW,int COL)
{
	int i=0;
	//横三行
	for(i=0;i<ROW;i++)
	{
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' ')
			{
				return board[i][0];
		}
	}
	//竖三列
	for(i=0;i<COL;i++)
	{
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[i][0]!=' ')
			{
				return board[0][i];
		}
	}
	//斜两列
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')
	{return board[0][0];}
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[1][1]!=' ')
	{	return board[0][2];}
	if(isfull(board,row,col)==1)
	{
	return 'c';//平局
	}
	else return 'd';//游戏未结束
}
