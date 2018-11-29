#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ROW 3
#define COL 3
char g_chess_board[ROW][COL];

void Init()
{
	//初始化
	for (int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col < COL; ++col)
		{
			g_chess_board[row][col] = ' ';
		}
	}
	
}

void print()
{
	//打印棋盘
	for (int row = 0; row < ROW; ++row)
	{
		printf(" | %c | %c | %c |\n",g_chess_board[row][0],
			g_chess_board[row][1],g_chess_board[row][2]);
		if (row != ROW - 1)
		{
			printf(" |---|---|---|\n");
		}
	}
}

void PlayerMove()
{
	//玩家落子
	while (1)
	{
		//提示玩家输入一个坐标
		printf("请玩家落子(输入坐标):");
		//读取玩家输入
		int row = -1;
		int col = -1;
		scanf("%d %d", &row, &col);
		//检验玩家输入
		//检验坐标是否在合理范围
		//玩家的输入的坐标对应位置是否有子
		if (row < 0 || row > ROW || col < 0 || col > COL)
		{
			printf("输入坐标非法,请重新输入!\n");
			continue;
		}
		if (g_chess_board[row][col] != ' ')
		{
			printf("当前位置有子,请重新输入!\n");
			continue;
		}
		g_chess_board[row][col] = 'x';
		break;
	}
}

void ComputerMove()
{
	//电脑落子
	printf("请电脑落子!\n");
	int row = 0;
	int col = 0;
	while (1)
	{
		row = rand() % ROW;
		col = rand() % COL;
		if (g_chess_board[row][col] == ' ')
		{
			g_chess_board[row][col] = '0';
			break;
		}
	}
}

int IsFull()
{
	for (int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col < COL; ++col)
		{
			if (g_chess_board[row][col] == ' ')
			{
				return 0;
			}
		}
	}return 1;
}

char CheckWinner()//检查游戏是否结束
{
	for (int row = 0; row < ROW; ++row)
	{   //行是否连在一起
		if (g_chess_board[row][0] == g_chess_board[row][1]
			&& g_chess_board[row][0] == g_chess_board[row][2]
			&& g_chess_board[row][0 != ' '])
		{
			return g_chess_board[row][0];
		}
	}
	for (int col = 0; col < COL; ++col)
	{   //列是否连在一起
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]
			&& g_chess_board[0][col] != ' ')
		{
			return g_chess_board[0][col];
		}
	}
	//检查对角线
	if (g_chess_board[0][0] == g_chess_board[1][1]
		&& g_chess_board[0][0] == g_chess_board[2][2]
		&& g_chess_board[0][0] != ' ')
	{
		return g_chess_board[0][0];
	}
	if (g_chess_board[2][0] == g_chess_board[1][1]
		&& g_chess_board[2][0] == g_chess_board[1][1]
		&& g_chess_board[2][0] != ' ')
	{
		return g_chess_board[2][0];
	}
	//检查和棋
	if (IsFull())
	{
		return 'q';
	}
	return ' ';
}

int main()
{
	char winner = ' ';
	Init();
	while (1)
	{
		print();
		PlayerMove();
		winner = CheckWinner();
		if (winner !=  ' ')
		{
			break;
		}
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' ')
		{
			break;
		}
	}
	if (winner == 'x')
	{
		printf("玩家获胜!\n");
	}
	else if (winner == '0')
	{
		printf("电脑获胜!\n");
	}
	else if (winner == 'q');
	{
		printf("和棋!\n");
	}
	system("pause");
	return 0;	
}