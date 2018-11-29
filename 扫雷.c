#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int Menu()
{
	printf("1. 开始游戏\n");
	printf("0. 退出游戏\n");
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MINE_COUNT 10
#define ROW 9
#define COL 9
int row = 0;
int col = 0;
//对于 mine_map, 使用'0'表示不是地雷, 使用'1'表示是地雷
char mine_map[ROW + 2][COL + 2];
//对于 show_map, 使用'*' 表示未打开的方块,对于打开的方块就是用具体的数字表示
char show_map[ROW + 2][COL + 2];
void srand(unsigned int seed);
void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2])
{
	//1.把数组进行初始化
	//对于 mine_map, 先把里面的所有元素都设置成'0'
	memset(mine_map, '0', (ROW + 2)*(COL + 2));
	//对于 show_map, 先把所有的元素都设置成'*'
	memset(show_map, '*', (ROW + 2)*(COL + 2));
	//2. 随机的布置雷阵
	srand(time(0));//随机种子,精确到毫秒的时间
	int mine_count = MINE_COUNT;
	while (mine_count > 0)
	{
		//在这个循环中随机设置地雷,每次设置完成一个,就--mine_count
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
//打印第一行的内容,四个空格 + 每一列的坐标
	printf("    ");
	for (int col = 1; col <= COL; ++col)
	{
		printf("%d ", col);
	}
	printf("\n");
	//打印具体的地图
	//打印第二行,地图的上边框
	for (int col = 1; col <= COL; ++col)
	{
		printf("---");
	}
	printf("\n");
	//按行打印地图中的具体内容
	for (int row = 1; row <= ROW; ++row)
	{
		//先打印出行号
		//1 => 01  2 => 02  10 => 10
		printf("%d02d| ", row);
		for (int col = 1; col <= COL; ++col)
		{
			printf("%c", map[row][col]);
		}
	}
}

//需要统计row, col位置的元素周围有几个雷,并且把结果更新到show_map中
void UpdateShowMap(char mine_map[ROW + 2][COL + 2], 
	char show_map[ROW + 2][COL + 2],int row, int col)
{
	row - 1, col - 1;
	row - 1, col;
	row - 1, col + 1;
	row, col - 1;
	row, col;//当前位置本身
	row, col + 1;
	row + 1, col - 1;
	row + 1, col;
	row + 1, col + 1;
}

void Game()
{
	//1. 初始化地图,布置雷阵
	int not_mine_count = 0;
	Init(mine_map, show_map);
	//2. 先打印show_map
	DisplayMap(show_map);
	//3. 提示用户输入坐标[1,ROW][1,COL]
	while (1)
	{
		int row = 0;
		int col = 0;
		printf("请输入要翻开的方块坐标(row, col):");
		scanf("%d %d", &row, &col);
		//4. 判定用户输入, 如果不合理, 则提示用户重新输入
		if (row <= 0 || row > ROW || col <= 0 || col > COL)
		{
			printf("您的输入不合法! 请重新输入!\n");
			continue;
		}
		//5. 判定玩家是否踩雷,如果踩雷,游戏结束,打印雷阵
		if (mine_map[row][col] == '1')
		{
			printf("游戏结束!\n");
			DisplayMap(mine_map);
			break;
		}
		//6. 如果玩家没有踩雷,判定玩家是否胜利(胜利就是 已经翻开的方块数 = 地图方块总数 - 地雷总数)
		++not_mine_count;
		if (not_mine_count == ROW * COL - MINE_COUNT)
		{
			printf("扫雷成功!\n");
			DisplayMap(mine_map);
			break;
		}
		//7. 如果游戏没有胜利,就需要统计当前位置周围有几个雷,打印show_map, 回到3
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
			printf("退出游戏!\n");
			break;
		}
		Game();
	}
}
