//�������
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

//0-999֮���ˮ�ɻ���  153 370 371 407
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,k,n;
	printf("ˮ�ɻ���:",n);
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

//ǰ����֮��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num = 0;
	int count = 0;//����count,�ڱ���ֵ��Ͳ��ܸı�
	int sum = 0;
	int tmp = 0;//������ʱ����,���������ӵļ���
	int i = 0;//������count
        scanf("%d%d", &num, &count );
	for(i = 0; i < count; i++)
	{
       tmp = tmp * 10 + num;//ѭ���������仰�����ڵݹ�
	   //�����п���������� 2, 2 + 20, 2 + 220, 2 + 2220...
	   sum += tmp;
	}
	printf("%d\n", sum);
    system("pause");
	return 0;
}




