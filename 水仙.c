#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int i;	//ԭ��
	for (i = 1; i <= 100000; i++)
	{
		int n = 1;//λ��
		int sum = 0;
		int j=i;
		while (j/=10)
		{
			n++;
		}
		j = i;
		while (j)
		{
			sum += pow(j % 10, n);
			j /=10;
		}
		if (i == sum)
			printf("%d ",i);
	}
}
