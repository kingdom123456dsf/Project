#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 20, M = 1 << N;
int f[M][N];
int w[N][N];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++ )
	{
		for(int j = 0; j < n; j ++ )
		{
			cin >> w[i][j];
		}
	}
	
	memset(f, 0x3f, sizeof f);
	f[1][0] = 0;//表示到第0个点,只有1个点故二进制也是1(f[1][0]) 
	
	//枚举所有状态 
	for(int i = 0; i < 1 << n; i ++ )
	{
		for(int j = 0; j < n; j ++ )
		{
			if(i >> j & 1)//j点得在状态中
			{
				for(int k = 0; k < n; k ++ )//上一步
					if(i >> k & 1)//上一步的点也得在状态中
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]); 
			} 
		}
	}
	
	cout << f[(1 << n) - 1][n - 1] << endl;
	
	return 0;
}
