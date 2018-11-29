#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ROW 3
#define COL 3
char g_chess_board[ROW][COL];

void Init()
{
	//��ʼ��
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
	//��ӡ����
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
	//�������
	while (1)
	{
		//��ʾ�������һ������
		printf("���������(��������):");
		//��ȡ�������
		int row = -1;
		int col = -1;
		scanf("%d %d", &row, &col);
		//�����������
		//���������Ƿ��ں���Χ
		//��ҵ�����������Ӧλ���Ƿ�����
		if (row < 0 || row > ROW || col < 0 || col > COL)
		{
			printf("��������Ƿ�,����������!\n");
			continue;
		}
		if (g_chess_board[row][col] != ' ')
		{
			printf("��ǰλ������,����������!\n");
			continue;
		}
		g_chess_board[row][col] = 'x';
		break;
	}
}

void ComputerMove()
{
	//��������
	printf("���������!\n");
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

char CheckWinner()//�����Ϸ�Ƿ����
{
	for (int row = 0; row < ROW; ++row)
	{   //���Ƿ�����һ��
		if (g_chess_board[row][0] == g_chess_board[row][1]
			&& g_chess_board[row][0] == g_chess_board[row][2]
			&& g_chess_board[row][0 != ' '])
		{
			return g_chess_board[row][0];
		}
	}
	for (int col = 0; col < COL; ++col)
	{   //���Ƿ�����һ��
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]
			&& g_chess_board[0][col] != ' ')
		{
			return g_chess_board[0][col];
		}
	}
	//���Խ���
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
	//������
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
		printf("��һ�ʤ!\n");
	}
	else if (winner == '0')
	{
		printf("���Ի�ʤ!\n");
	}
	else if (winner == 'q');
	{
		printf("����!\n");
	}
	system("pause");
	return 0;	
}