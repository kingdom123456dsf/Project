#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 210, INF = 1e9;
int d[N][N];//存储从a到b的最短路径
int n, m, Q;//n个点，m个边，Q个询问 

void floyd()
{
	for(int k = 1; k <= n; k ++ )
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= n; j ++ )
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);	
}

int main()
{
	cin >> n >> m >> Q;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= n; j ++ )
			if(i == j) d[i][j] = 0;//自环为0	
			else d[i][j] = INF;//否则就先初始化为最大值
			
	while(m -- )
	{
		int x, y, w;
		cin >> x >> y >> w;
		
		d[x][y] = min(w, d[x][y]);//重边取最短 
	}
	
	floyd();//跑一次以后，d存的就是两点之间的最短路了 
	
	while(Q -- )
	{
		int x, y;
		cin >> x >> y;
		
		if(d[x][y] > INF / 2) puts("impossible");//没有最短路 
		else cout << d[x][y] << endl;
	}
	
	return 0;
}
