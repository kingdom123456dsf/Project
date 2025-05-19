#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510, M = 100010;

struct Edge{
	int a, b, w;
}edges[M];//M条边 

int dist[N], backup[N];
int n, m, k;

void bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for(int i = 0; i < k; i ++ )//最多经过k个 
	{
		memcpy(backup, dist, sizeof dist);//备份，防止联动 
		for(int j = 0; j < m; j ++ )//边 
		{
			auto e = edges[j];
			// b = min(b, a + w);
			dist[e.b] = min(dist[e.b], backup[e.a] + e.w);
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < m; i ++ )
	{
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	}
	
	bellman_ford();
	
	//因为可能有负权边，所以不存在最短路径的值可能比正无穷小 
	if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
	else cout << dist[n] << endl;	
	
	return 0;
}
