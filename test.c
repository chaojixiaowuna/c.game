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
	
	//����һ����ά���� �������д洢ÿһ�����λ��
	char board[row][col]={0};//��.h�ļ��и��� row col ��ֵ ���ɸı����������
	//��ӡ�������� Ȼ���ٴ�ӡ����
	InitBoard(board,row,col);//��ʼ������
	//��ӡ����
	Displayboard(board,row,col);
  /*
  |   |
__|___|__
  |   |
__|___|__
  |   |
  */
	//����
	while(1)
	{
    //�������
	playermove(board,row,col);
	Displayboard(board,row,col);
	//�ж�����Ƿ�ʤ��
	ret=iswin(board,row,col);
		if(ret!='d')
			break;
	//��������
	PCmove(board,row,col);
	Displayboard(board,row,col);
	//�жϵ����Ƿ�ʤ��
	ret=iswin(board,row,col);
	if(ret!='d')
		break;
	}
	if(ret=='*')
		printf("���ʤ��");
	else if(ret=='#')
	printf("����ʤ��");
	else
		printf("ƽ��");
}
void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������ָ��\n");
		scanf("%d",&input);
		switch(input)
		{
         case 1:
			printf("��������Ϸ��ʼ\n");
			game();
			break;
        case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("ָ�������������������ָ��\n");
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