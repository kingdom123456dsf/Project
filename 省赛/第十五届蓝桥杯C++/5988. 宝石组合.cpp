#include<iostream>
#include<cstdio>

using namespace std;

const int N = 100010;
int cnt[N];//用来统计每个数的出现次数
int n;

int main()
{
	scanf("%d", &n);
	while(n --)
	{
		int x;
		scanf("%d", &x);
		cnt[x] ++;//统计每个数的出现次数 
	}
	
	for(int i = N - 1; i >= 1; i -- )//枚举公约数
	{
		int c = 0;//统计为多少个数的公约数 
		for(int j = i; j <= N - 1; j += i )//枚举倍数 
		{
			c += cnt[j];
		}
		if(c >= 3)//当前i是大于3个数的公约数 
		{
			c = 0;//清空 
			for(int j = i; j <= N - 1 && c < 3; j += i )
			{
				//cnt[j]相同数的出现次数 
				for(int k = 0; k < cnt[j] && c < 3; k ++, c ++ )
				{
					printf("%d ", j);//输出字典序最小的三个 
				}
			}
			printf("\n");
			break;
		}
	} 
	
	
	return 0;	
} 
