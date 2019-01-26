//1. 写一个函数返回参数二进制中 1 的个数 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
    int num = 0;
	while (value)//value为0时跳出循环
	{    //如果余数为1,则num加1
		 //将得到的商再付给value
		if (value % 2)
			num++;
		value = value / 2;
	}
	return num;
}

int main()
{
	int i = 0;
	int num = 0;
	printf("请输入一个正数: ");
	scanf("%d", &i);
	num = count_one_bits(i);//num为记录1 的个数
	printf("num = %d\n", num);
	system("pause");
	return 0;
}

//2. 2.获取一个数二进制序列中所有的偶数位和奇数位， 
分别输出二进制序列。 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int i = 0;
	int arr1[16], arr2[16];
	scanf("%d", &a);
	while (i < 32)
	{
		arr1[i / 2] = a % 2;
		a = a >> 1;

		i++;
		arr2[(i - 1) / 2] = a % 2;
		a = a >> 1;
		i++;
	}
	printf("奇数列二进制序列为:");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", arr1[i]);
	}
	printf("\n偶数列二进制序列为:");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", arr2[i]);
	}
	system("pause");
	return 0;
}

//3. 输出一个整数的每一位

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	printf("请输入一个整数：\n");
	scanf("%d", &n);
	while (n)
	{
		if (n < 0)
		{
			n = -n;
		}
		printf("   %d\n", n % 10);
		n = n / 10;
	}
	system("pause");
	return 0;
}
//4.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
int main()
{
	int m = 0;
	int n = 0;
	int q = 0;
	int i = 0;
	int count = 0;
	printf("请输入两个数字：");
	scanf("%d%d", &m, &n);
	q = m^n;  // 两个数按位异或，对应不同的位将会置1
	while (q)
	{
		q = q&(q - 1);  //按位与方法计算一个整数中比特位为1的个数
		count++;
	}
	printf("count=%d", count);
	system("pause");
	return 0;
}