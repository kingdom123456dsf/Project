#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 2210, INF = 1e9;
int f[N][N];
int n;

void floyd()
{
	for(int k = 1; k <= n; k ++ )
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= n; j ++ )
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);			
}

int main()
{
	n = 2022;
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= n; j ++ )
		{
			if(i == j) f[i][j] = 0;
			else f[i][j] = INF;
		}
	}
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= n; j ++ )
		{
			if(abs(i - j) <= 21) f[i][j] = i / __gcd(i, j) * j;
			else continue;
		}
	}
	
	floyd();
	
	cout << f[1][2021] << endl;
	
	return 0;
}
