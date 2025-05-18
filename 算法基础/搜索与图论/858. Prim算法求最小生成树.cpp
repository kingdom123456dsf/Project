#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];//稠密图用邻接矩阵
int dist[N];
bool st[N];

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	
	int res = 0;//存储边和 
	for(int i = 0; i < n; i ++ )
	{
		int t = -1;
		for(int j = 1; j <= n; j ++ )
			if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
			
		//当不是第一个点且更新的点的距离是正无穷 
		if(i && dist[t] == INF) return INF;
		
		if(i) res += dist[t];//不是根节点就可以加上边距离了
		st[t] = true; 	
		
		for(int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);//更新点到集合的最短距离 
	}	
	
	return res;
}

int main()
{
	memset(g, 0x3f, sizeof g);//初始化邻接矩阵 
	
	scanf("%d%d", &n, &m);
	while(m -- )
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);//无向图，赋两次值即可 
	}
	
	int t = prim();
	
	if(t == INF) puts("impossible");
	else printf("%d", t);
	
	return 0;
}
