#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 510;//点
int g[N][N];//存储权重
int dist[N];//记录1~n的最短路径 
bool st[N];//记录每个点是否有最短路 
int n, m;//点，边

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);//先将距离初始化为正无穷 
	
	dist[1] = 0;//别忘记！！！ 
	
	for(int i = 0; i < n; i ++ )//有n个点，遍历n次 
	{
		int t = -1;
		for(int j = 1; j <= n; j ++ )
		{
			//找到当前点的最短路径
			if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j; 
		}
		
		st[t] = true;//1~t的最短路已经有了 
		
		for(int j = 1; j <= n; j ++ )
		{
			dist[j] = min(dist[j], dist[t] + g[t][j]);//1到j 和 1到t到j的最小值 
		}
	}
	
	//若是1~n的距离还是正无穷，证明1~n无最短路 
	if(dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];	
} 

int main()
{
 	scanf("%d%d", &n, &m);
 	
 	memset(g, 0x3f, sizeof g);//将点的距离初始化为正无穷
	
	while(m -- )
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		
		g[x][y] = min(g[x][y], w);
	}
 	
	printf("%d", dijkstra());
	  
	return 0;
}
