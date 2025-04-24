#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 510;
int g[N][N], f[N][N];
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= i; j ++ )
		{
			cin >> g[i][j];
		}
	}
	
	memset(f, -0x3f, sizeof f);
	f[0][0] = 0;
	//可以由正上方或者是左上方走来
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= i; j ++ )
		{
			f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + g[i][j];
		}
	}
	
	int res = -5e6;
	for(int i = 1; i <= n; i ++ )
	{
		res = max(res, f[n][i]);
	}
	cout << res << endl;
	
	return 0;
}
