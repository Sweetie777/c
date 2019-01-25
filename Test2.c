//输出菱形
#include<stdio.h>
main ()
{
	int i, j, row;
	for(row = 1; row <= 7; row++)
	{
		for(i = 1; i <=7 - row; i++)
		{
			printf("");
		}
		for(j = 1; j <= 2*row - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(row = 1; row <= 6; row++)
	{
		for(i = 1; i <= row; i++)
		{
			printf("");
		}
		for(j = 1; j <= 2*(7 - row)-1; j++)
		{
			printf("*");
		}
			printf("\n");
	}
	getch();
}

//0-999之间的水仙花数  153 370 371 407
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,k,n;
	printf("水仙花数:",n);
	for (n=100; n<1000; n++);
	{
		j = n/100;
		j = n/10 - i*10;
		k = n%10;
		if(n == i*i*i+j*j*j+k*k*k)
			printf("%d\n",n);

	}
	system("pause");
	return 0;
}

//前五项之和
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num = 0;
	int count = 0;//变量count,在被赋值后就不能改变
	int sum = 0;
	int tmp = 0;//定义临时变量,来接收增加的加数
	int i = 0;//来遍历count
        scanf("%d%d", &num, &count );
	for(i = 0; i < count; i++)
	{
       tmp = tmp * 10 + num;//循环体里的这句话类似于递归
	   //例子中可以这样理解 2, 2 + 20, 2 + 220, 2 + 2220...
	   sum += tmp;
	}
	printf("%d\n", sum);
    system("pause");
	return 0;
}




