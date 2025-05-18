#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 210, M = 20010;
int d[N][N];
int n, m, k;

void floyd()
{
	for(int k = 1; k <= n; k ++ )
	{
		for(int i = 1; i <= n; i ++ )
		{
			for(int j = 1; j <= n; j ++ )
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= n; j ++ )
		{
			if(i != j) d[i][j] = 1e9;
			else d[i][j] = 0;
		}
	}
	
	while(m -- )
	{
		int x, y, z;
		cin >> x >> y >> z;
		d[x][y] = min(z, d[x][y]);
	}
	
	floyd();
	
	while(k -- )
	{
		int x, y;
		cin >> x >> y;
		if(d[x][y] > 1e9 / 2) puts("impossible");
		else cout << d[x][y] << endl;
	}	
	
	return 0;
} 
