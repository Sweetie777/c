//1. дһ���������ز����������� 1 �ĸ��� 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
    int num = 0;
	while (value)//valueΪ0ʱ����ѭ��
	{    //�������Ϊ1,��num��1
		 //���õ������ٸ���value
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
	printf("������һ������: ");
	scanf("%d", &i);
	num = count_one_bits(i);//numΪ��¼1 �ĸ���
	printf("num = %d\n", num);
	system("pause");
	return 0;
}

//2. 2.��ȡһ�������������������е�ż��λ������λ�� 
�ֱ�������������С� 
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
	printf("�����ж���������Ϊ:");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", arr1[i]);
	}
	printf("\nż���ж���������Ϊ:");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", arr2[i]);
	}
	system("pause");
	return 0;
}

//3. ���һ��������ÿһλ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	printf("������һ��������\n");
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
	printf("�������������֣�");
	scanf("%d%d", &m, &n);
	q = m^n;  // ��������λ��򣬶�Ӧ��ͬ��λ������1
	while (q)
	{
		q = q&(q - 1);  //��λ�뷽������һ�������б���λΪ1�ĸ���
		count++;
	}
	printf("count=%d", count);
	system("pause");
	return 0;
}