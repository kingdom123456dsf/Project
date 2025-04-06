#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 110, M = 2 * 100010;//M代表重量
int w[N];
bool f[N][M]; 
int n;

int main()
{
	scanf("%d", &n);
	
	//个数从1~n 
	int m;//总重量 
	for(int i = 1; i <= n; i ++ )
	{
		scanf("%d", &w[i]);
		m += w[i];
	}
	
	f[0][0] = true;//0个砝码，重量为0
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 0; j <= m; j ++ )
		{
			//因为是bool 
			f[i][j] = f[i - 1][j] || f[i - 1][abs(j - w[i])] || f[i - 1][j + w[i]];
			//j - w[i]可能为负，故abs；j + w[i]可能超过1e5,故数据范围要*2 
		} 
	}
	
	int res = 0;
	for(int j = 1; j <= m; j ++ )
	{
		if(f[n][j]) res ++;
	}
	
	printf("%d", res);
		
	return 0;
}
