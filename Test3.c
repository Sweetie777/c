//�ݹ�ͷǵݹ鷽ʽ�ֱ�ʵ�����n��쳲�������
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


//дһ������ʵ��n^k,ʹ�õݹ�ʵ��
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

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��.
//���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19
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
	printf("������һ�������� ");
	scanf("%d", &a);
	printf("��λ��֮��Ϊ��%d\n", DigitSum(a));
	return 0;
}

//��дһ������reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
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
        string[len-1] = '\0';// ���һ���ַ����´εݹ�ʱ���ٴ���
        reverse_string(string+1); // �ݹ����     
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

//�ݹ�ͷǵݹ鷽ʽʵ��strlen
#include<stdio.h>
int my_strlen1(const char *arr)//�ǵݹ鷽ʽ:������ʽ
{
	int count = 0;
	while (*arr)
	{
		arr++;
		count++;
	}
	return count;
}
int my_strlen2(char *arr)//�ݹ鷽ʽ
{
	if (*arr == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_strlen2(arr + 1);//�ݹ�����Լ�����arr+1����ȥ
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

//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
#include<stdio.h>
#include<windows.h>
int D_N(int n)//�ݹ�
{
	if (n == 1)
	{
		return 1;
	}
	return n*D_N(n - 1);
}
int FD_N(int n)//�ǵݹ�
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
	printf("������n:");
	scanf_s("%d", &n);
	int DS = 0;
	int FDS = 0;
	DS = D_N(n);
	FDS = FD_N(n);
	printf("�ݹ���:%d\n", DS);
	printf("�ǵݹ���:%d\n", FDS);

	system("pause");
	return 0;
}


//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
#include<stdio.h>
#include<windows.h>
void D_S(int n)//�ݹ�
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
	printf("������n:");
	scanf_s("%d", &n);
	printf("�ݹ���:\n");
	D_S(n);

	system("pause");
	return 0;
}
