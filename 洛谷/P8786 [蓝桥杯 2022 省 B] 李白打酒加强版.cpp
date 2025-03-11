#include<iostream>

using namespace std;

const int N = 110, MOD = 1e9 + 7;
int f[N][N][N];
int n, m;

int main()
{
	cin >> n >> m;
	
	f[0][0][2] = 1;//最开始是没有店，没有花，两斗酒
	for(int i = 0; i <= n; i++)//店 
	{
		for(int j = 0; j <= m; j++)//花 
		{
			for(int k = 0; k <= m; k++)//持有酒的数量不能比花多，不然到最后酒的数量不能为0了 
			{
				if(i && k % 2 == 0) f[i][j][k] = (f[i][j][k] + f[i - 1][j][k / 2]) % MOD;//最后为店
				if(j) f[i][j][k] = (f[i][j][k] + f[i][j - 1][k + 1]) % MOD;				
			} 
		}
	}
	
	cout << f[n][m - 1][1] << endl;//最后一次是花,所有有n个店，m - 1朵花， 1斗酒 
	
	return 0;
}
