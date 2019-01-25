//递归和非递归方式分别实现求第n个斐波那契数
#include<stdio.h>
int fib_1(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib_1(n - 1) + fib_1(n - 2);
}
int fib_2(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	n = 10;
	printf("%d\n", fib_1(n));
	printf("%d\n", fib_2(n));

	system("pause");
	return 0;
}


//写一个函数实现n^k,使用递归实现
#include<stdio.h>
int my_pow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	return n * my_pow(n, k-1);
}
void main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);
	printf("%d\n", my_pow(n, k));
	system("pause");
}

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和.
//例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int DigitSum(int n)
{
	int sum = 0;
	int m = 0;
	if (n != 0)
	{
		m = n % 10;
		n = n / 10;
		sum = m + DigitSum(n);
	}
	return sum;
}
int main()
{
	int a;
	printf("请输入一个整数： ");
	scanf("%d", &a);
	printf("各位数之和为：%d\n", DigitSum(a));
	return 0;
}

//编写一个函数reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
#include <stdio.h>
char * reverse_string(char * string)   
{    
    int len = 0;
    char temp;  
    char *end = string;  
    while(*end != '\0')  
    {  
        end++; 
	len++;
    }  
    if( !string )     
    {     
        return NULL;  
    }         
    if( len > 1 )     
    { 
	temp = string[0];
        string[0] = string[len-1];        
        string[len-1] = '\0';// 最后一个字符在下次递归时不再处理
        reverse_string(string+1); // 递归调用     
        string[len-1] = temp;
    }     
    return string;
}  
int main(void)
{
	char arr[] = "12345";
	printf("%s\n",reverse_string(arr));
	return 0;
}

//递归和非递归方式实现strlen
#include<stdio.h>
int my_strlen1(const char *arr)//非递归方式:计数方式
{
	int count = 0;
	while (*arr)
	{
		arr++;
		count++;
	}
	return count;
}
int my_strlen2(char *arr)//递归方式
{
	if (*arr == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_strlen2(arr + 1);//递归调用自己，将arr+1传进去
	}
}
int main()
{
	char arr[] = "abcdef";
	my_strlen1(arr);
	my_strlen2(arr);
	printf("%d\n", my_strlen1(arr));
	printf("%d\n", my_strlen2(arr));

	return 0;
}

//递归和非递归分别实现求n的阶乘
#include<stdio.h>
#include<windows.h>
int D_N(int n)//递归
{
	if (n == 1)
	{
		return 1;
	}
	return n*D_N(n - 1);
}
int FD_N(int n)//非递归
{
	int sum = 1;
	for (; n > 0; n--)
	{
		sum *= n;
	}
	return sum;
}
int main()
{
	int n = 5;
	printf("请输入n:");
	scanf_s("%d", &n);
	int DS = 0;
	int FDS = 0;
	DS = D_N(n);
	FDS = FD_N(n);
	printf("递归结果:%d\n", DS);
	printf("非递归结果:%d\n", FDS);

	system("pause");
	return 0;
}


//递归方式实现打印一个整数的每一位
#include<stdio.h>
#include<windows.h>
void D_S(int n)//递归
{
	if (n < 10)
	{
		printf("%d", &n);
		return 0;
	}
	D_S(n / 10);
	printf("%d", n % 10);
}
int main()
{
	int n = 5;
	printf("请输入n:");
	scanf_s("%d", &n);
	printf("递归结果:\n");
	D_S(n);

	system("pause");
	return 0;
}
