#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 10010, M = 200010, K = 110;
int h[N], e[M], ne[M], idx;
int q[N], dist[N][K], id[N];
int n, m, k, s;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs(int p)
{
	int hh = 0, tt = -1;
	for(int i = 1; i <= n; i ++ )
	{
		if(id[i] == p)//售卖该种商品 
		{
			dist[i][p] = 0;
			q[++ tt] = i;//放入队列 商店id 
		}
	}
	
	while(hh <= tt)
	{
		int t = q[hh ++ ];
		
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(dist[j][p] == -1)
			{
				dist[j][p] = dist[t][p] + 1;
				q[++ tt] = j;
			}
		}
	}
}

int main()
{
	while((cin >> n >> m >> k >> s))
	{		
		for(int i = 1; i <= n; i ++ ) cin >> id[i];//每个商店的商品种类
		
		memset(h, -1, sizeof h);
		memset(dist, -1, sizeof dist);
		idx = 0;
		for(int i = 1; i <= m; i ++ )
		{
			int u, v;
			cin >> u >> v;
			add(u, v), add(v, u);
		} 
		
		for(int i = 1; i <= k; i ++) bfs(i);//给每个商品种类跑一遍暴力 
		
		for(int i = 1; i <= n; i ++ )//从每一起点出发
		{
			int res = 0;
			sort(dist[i] + 1, dist[i] + 1 + k);//从小到大排序
			
			for(int j = 1; j <= s; j ++ ) res += dist[i][j];
			cout << res << " " ; 
		} 
		puts("");
	}
	
	
	return 0;
}
