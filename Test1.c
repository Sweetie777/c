//打印100-200之间的素数
#include<stdio.h>
#include<math.h>
    int main()
    {
    int i,j,k;
    for(i=101;i<=200;i+=2)   //偶数一定不是素数,从101开始,i每次循环一次加二
    {
        k=sqrt(i);  //i开平方,如果可以的话就不是素数
        for(j=2;j<=k;j++)
        if(i%j==0)
           break;    //如果存在一个数能整除它,就退出循环
        if(j>k)
           printf("%d",i);  //循环结束,如果没有数可以整除这个数,就输出这个数
     }
     system("pause");
     return 0;
     }

//素数2
#include<stdio.h>
#include<stdlib.h>
int isprimenumber(unsigned int n);
int main()
{
	int i = 0;//定义一个循环变量并进行初始化
	int count = 0;//定义一个计数器并初始化
	printf("100-200之间的素数有:\n");
	for (i=100; i<=200; i++)
	{
		if (isprimenumber(i))//如果i是素数
		{
			printf("%d",i);
			count++;
		}
	}
	printf("\n合计共有%d个",count);
	return 0;
}
int isprimenumber(unsigned int n)
{
	unsigned int i = 0;//定义一个循环变量并初始化为0
	if(n<2)
	{
		return 0;
	}
	for(i=2; i<=(int)sqrt(n); i++)
	{
		if((n%i)==0)
		{
			return 0;
		}
	}
	return 1;
}system("pause");





//输出九九乘法表
#include<stdio.h>
int main()
    {
    int i,j;
    for(i=1;i<=9;i++)  //循环计算1-9
     {
       for(j=1;j<=i;j++) //输出数i的i个乘法项
        {
          printf("%d*%d=%d\t,j,i,i*j");
        }
    if(i==3)
    printf("\t九九乘法表");  //在第三行输出九九乘法表
    printf("\n");
     }
    getchar();
    return 0;
    }


//判断1000-2000年之间的闰年
#include<stdio.h>
int main()
    {
    int i = 0;                
    for (i = 1000; i <= 2000; i++)        //建立1000-2000的循环
    {
        if (i % 4 == 0 && i % 100 != 0)         //普通年,能被4整除且不能被100整除
        {
            printf("%5d", i);
        }
        if (i % 400 == 0)             //世纪年,能被400整除
        {
        printf("%5d", i);
        }
    }
    return 0;
    }


//1-100中出现多少次数字9
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int k = 0;
	for (i = 1; i < 100; i++)
	{
		if(i%10 == 9)
		{
			k++;
		}
		if(i/10 == 9)
		{
			k++;
		}
	}
	printf("%d\n",k);
	system("pause");
	return 0;
}