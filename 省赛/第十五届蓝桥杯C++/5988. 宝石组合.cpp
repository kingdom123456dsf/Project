#include<iostream>
#include<cstdio>

using namespace std;

const int N = 100010;
int cnt[N];//����ͳ��ÿ�����ĳ��ִ���
int n;

int main()
{
	scanf("%d", &n);
	while(n --)
	{
		int x;
		scanf("%d", &x);
		cnt[x] ++;//ͳ��ÿ�����ĳ��ִ��� 
	}
	
	for(int i = N - 1; i >= 1; i -- )//ö�ٹ�Լ��
	{
		int c = 0;//ͳ��Ϊ���ٸ����Ĺ�Լ�� 
		for(int j = i; j <= N - 1; j += i )//ö�ٱ��� 
		{
			c += cnt[j];
		}
		if(c >= 3)//��ǰi�Ǵ���3�����Ĺ�Լ�� 
		{
			c = 0;//��� 
			for(int j = i; j <= N - 1 && c < 3; j += i )
			{
				//cnt[j]��ͬ���ĳ��ִ��� 
				for(int k = 0; k < cnt[j] && c < 3; k ++, c ++ )
				{
					printf("%d ", j);//����ֵ�����С������ 
				}
			}
			printf("\n");
			break;
		}
	} 
	
	
	return 0;	
} 
