#include<iostream>

using namespace std;

const int N = 110;
int w[N][N];//花生数量
int f[N][N];//状态 
int t,n,m; 

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> m;//行列 
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
			{
				cin >> w[i][j];
			}
			
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];
			}
		}
		
		cout << f[n][m] << endl;
	}
	
	return 0;
}
