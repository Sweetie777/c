//1. Ԥ����ˮ�������
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;
	for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				for (D = 1; D <= 5; D++)
				{
					for (E = 1; E <= 5; E++)
					{
						if ((B == 2) + (A == 3) == 1 &&
							(B == 2) + (E == 4) == 1 &&
							(C == 1) + (D == 2) == 1 &&
							(C == 5) + (D == 3) == 1 &&
							(E == 4) + (A == 1) == 1)//����������
						if (120 == A*B*C*D*E)
							//�������β�ͬ,�����Ϊ��ֵ120��ɸѡ�ظ�����
						{
							printf("A = %d B = %d C = %d D = %d E = %d\n", A, B, C, D, E);
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}

//2. ������
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char killer;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
		{
			printf("%c������\n", killer);
			break;
		}
	}
	system("pause");
	return 0;
}

//3. ��ӡ�������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 14
void main()
{
	int i, j, k, n = 0, a[N][N];  //�����ά����a[14][14]
	while (n <= 0 || n >= 13){  //���ƴ�ӡ��������Ҫ̫�󣬹���������ʾ���淶
		printf("������Ҫ��ӡ��������");
		scanf("%d", &n);
	}
	printf("%d������������£�\n", n);
	for (i = 1; i <= n; i++)
		a[i][1] = a[i][i] = 1;  //���ߵ�������Ϊ1����Ϊ����ѭ����1��ʼ������Ϊa[i][1]Ϊ��һ����
	for (i = 3; i <= n; i++)
	    for (j = 2; j <= i - 1; j++)
		    a[i][j] = a[i - 1][j - 1] + a[i - 1][j];  //�����ߵ����ⶼ������������֮��
	for (i = 1; i <= n; i++){
		for (k = 1; k <= n - i; k++)
			printf("   ");  //��һ����Ҫ���������֮ǰ���Ͽո�ռλ�����������������
		for (j = 1; j <= i; j++)  //j<=i��ԭ���ǲ��������������ֻ���������Ҫ����
			printf("%6d", a[i][j]);

		printf("\n");  //��һ��������Ժ��м�����һ�е����
	}
	system("pause");
	printf("\n");
}