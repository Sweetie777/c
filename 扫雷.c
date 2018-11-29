#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int Menu()
{
	printf("1. ��ʼ��Ϸ\n");
	printf("0. �˳���Ϸ\n");
	printf("����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MINE_COUNT 10
#define ROW 9
#define COL 9
int row = 0;
int col = 0;
//���� mine_map, ʹ��'0'��ʾ���ǵ���, ʹ��'1'��ʾ�ǵ���
char mine_map[ROW + 2][COL + 2];
//���� show_map, ʹ��'*' ��ʾδ�򿪵ķ���,���ڴ򿪵ķ�������þ�������ֱ�ʾ
char show_map[ROW + 2][COL + 2];
void srand(unsigned int seed);
void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2])
{
	//1.��������г�ʼ��
	//���� mine_map, �Ȱ����������Ԫ�ض����ó�'0'
	memset(mine_map, '0', (ROW + 2)*(COL + 2));
	//���� show_map, �Ȱ����е�Ԫ�ض����ó�'*'
	memset(show_map, '*', (ROW + 2)*(COL + 2));
	//2. ����Ĳ�������
	srand(time(0));//�������,��ȷ�������ʱ��
	int mine_count = MINE_COUNT;
	while (mine_count > 0)
	{
		//�����ѭ����������õ���,ÿ���������һ��,��--mine_count
		//[1, ROW]
		int row = rand() % 9 + 1;
		int col = rand() % 9 + 1;
		if (mine_map[row][col] == '0')
		{
			mine_map[row][col] = '1';
			--mine_count;
		}
	}
}

void DisplayMap(char map[ROW + 2][COL + 2])
{
//��ӡ��һ�е�����,�ĸ��ո� + ÿһ�е�����
	printf("    ");
	for (int col = 1; col <= COL; ++col)
	{
		printf("%d ", col);
	}
	printf("\n");
	//��ӡ����ĵ�ͼ
	//��ӡ�ڶ���,��ͼ���ϱ߿�
	for (int col = 1; col <= COL; ++col)
	{
		printf("---");
	}
	printf("\n");
	//���д�ӡ��ͼ�еľ�������
	for (int row = 1; row <= ROW; ++row)
	{
		//�ȴ�ӡ���к�
		//1 => 01  2 => 02  10 => 10
		printf("%d02d| ", row);
		for (int col = 1; col <= COL; ++col)
		{
			printf("%c", map[row][col]);
		}
	}
}

//��Ҫͳ��row, colλ�õ�Ԫ����Χ�м�����,���Ұѽ�����µ�show_map��
void UpdateShowMap(char mine_map[ROW + 2][COL + 2], 
	char show_map[ROW + 2][COL + 2],int row, int col)
{
	row - 1, col - 1;
	row - 1, col;
	row - 1, col + 1;
	row, col - 1;
	row, col;//��ǰλ�ñ���
	row, col + 1;
	row + 1, col - 1;
	row + 1, col;
	row + 1, col + 1;
}

void Game()
{
	//1. ��ʼ����ͼ,��������
	int not_mine_count = 0;
	Init(mine_map, show_map);
	//2. �ȴ�ӡshow_map
	DisplayMap(show_map);
	//3. ��ʾ�û���������[1,ROW][1,COL]
	while (1)
	{
		int row = 0;
		int col = 0;
		printf("������Ҫ�����ķ�������(row, col):");
		scanf("%d %d", &row, &col);
		//4. �ж��û�����, ���������, ����ʾ�û���������
		if (row <= 0 || row > ROW || col <= 0 || col > COL)
		{
			printf("�������벻�Ϸ�! ����������!\n");
			continue;
		}
		//5. �ж�����Ƿ����,�������,��Ϸ����,��ӡ����
		if (mine_map[row][col] == '1')
		{
			printf("��Ϸ����!\n");
			DisplayMap(mine_map);
			break;
		}
		//6. ������û�в���,�ж�����Ƿ�ʤ��(ʤ������ �Ѿ������ķ����� = ��ͼ�������� - ��������)
		++not_mine_count;
		if (not_mine_count == ROW * COL - MINE_COUNT)
		{
			printf("ɨ�׳ɹ�!\n");
			DisplayMap(mine_map);
			break;
		}
		//7. �����Ϸû��ʤ��,����Ҫͳ�Ƶ�ǰλ����Χ�м�����,��ӡshow_map, �ص�3
		UpdateShowMap(show_map, mine_map, row, col);
		DisplayMap(show_map);

	}
}

void Start()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 0)
		{
			printf("�˳���Ϸ!\n");
			break;
		}
		Game();
	}
}
