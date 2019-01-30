//1. 编写函数： 
unsigned int reverse_bit(unsigned int value); 
这个函数的返回值value的二进制位模式从左到右翻转后的值。

#include <stdio.h>
#include <stdlib.h>
int reverse_bit(unsigned int value)
{
	int i = 0;
	int ret = 0;
	int bit = 0;
	for (i = 0; i < 32; i++)
	{
		ret = ret << 1;
		bit = value & 1;
		value = value >> 1;
		ret = bit | ret;

	}
	return ret;
}

int main()
{
	printf("%u\n", reverse_bit(2550136832));
	system("pause");
	return 0;
}

//2. 两个数的平均数
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", (a&b) + ((a^b) >> 1));
	system("pause");
	return 0;
}
//3. 一组数中只有一个数字出现了一次,其他都是成对出现,请找出这个数字
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = { 1, 2, 3, 2, 1, };
	int a = arr[0];
	int num = sizeof(arr) / sizeof(arr[0]);//数组长度
	for (int i = 1; i < num; i++)
	{
		a ^= arr[i];//异或运算
	}
	printf("%d\n", a);
	system("pause");
	return 0;
}
//4. 用库函数修改数组内容
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
void reverse(char *start, char *end)
{
	assert(start);
	assert(end);
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reverse_str(char *str, int sz)
{
	assert(str);
	char *str1 = str;
	char *left = str;
	char *right = str + sz - 1;
	reverse(left, right);
	while (*str)
	{
		left = str1;
		while ((*str != '0') && (*str != ' '))
		{
			str++;

		}
		right = str - 1;
		reverse(left, right);
		if (*str1 == ' ')
		{
			str1++;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	int sz = strlen(arr);
	reverse_str(arr, sz);
	printf("%s", arr);
	getchar();
	return 0;
}