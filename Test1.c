//��ӡ100-200֮�������
#include<stdio.h>
#include<math.h>
    int main()
    {
    int i,j,k;
    for(i=101;i<=200;i+=2)   //ż��һ����������,��101��ʼ,iÿ��ѭ��һ�μӶ�
    {
        k=sqrt(i);  //i��ƽ��,������ԵĻ��Ͳ�������
        for(j=2;j<=k;j++)
        if(i%j==0)
           break;    //�������һ������������,���˳�ѭ��
        if(j>k)
           printf("%d",i);  //ѭ������,���û�����������������,����������
     }
     system("pause");
     return 0;
     }

//����2
#include<stdio.h>
#include<stdlib.h>
int isprimenumber(unsigned int n);
int main()
{
	int i = 0;//����һ��ѭ�����������г�ʼ��
	int count = 0;//����һ������������ʼ��
	printf("100-200֮���������:\n");
	for (i=100; i<=200; i++)
	{
		if (isprimenumber(i))//���i������
		{
			printf("%d",i);
			count++;
		}
	}
	printf("\n�ϼƹ���%d��",count);
	return 0;
}
int isprimenumber(unsigned int n)
{
	unsigned int i = 0;//����һ��ѭ����������ʼ��Ϊ0
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





//����žų˷���
#include<stdio.h>
int main()
    {
    int i,j;
    for(i=1;i<=9;i++)  //ѭ������1-9
     {
       for(j=1;j<=i;j++) //�����i��i���˷���
        {
          printf("%d*%d=%d\t,j,i,i*j");
        }
    if(i==3)
    printf("\t�žų˷���");  //�ڵ���������žų˷���
    printf("\n");
     }
    getchar();
    return 0;
    }


//�ж�1000-2000��֮�������
#include<stdio.h>
int main()
    {
    int i = 0;                
    for (i = 1000; i <= 2000; i++)        //����1000-2000��ѭ��
    {
        if (i % 4 == 0 && i % 100 != 0)         //��ͨ��,�ܱ�4�����Ҳ��ܱ�100����
        {
            printf("%5d", i);
        }
        if (i % 400 == 0)             //������,�ܱ�400����
        {
        printf("%5d", i);
        }
    }
    return 0;
    }


//1-100�г��ֶ��ٴ�����9
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