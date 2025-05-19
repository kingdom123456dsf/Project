#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int n, m;
int p[N];//用于并查集 (点)

struct Edge{
	int a, b, w;
//	bool operator< (const Edge &W)const
//	{
//		return w < W.w;
//	} 
}edges[N * 2];

int find(int x)//合并集合 
{
	if(p[x] != x) p[x] = find(p[x]); 
	return p[x];
}

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

int kruskal()
{
	sort(edges, edges + m, cmp);
	
	for(int i = 1; i <= n; i ++ ) p[i] = i;//初始化并查集
	
	int res = 0, cnt = 0;//记录结果和边数 
	for(int i = 0; i < m; i ++ )
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		
		a = find(a), b = find(b);//找到父节点
		if(a != b)
		{
			p[a] = b;//合并 
			res += w;//答案加上权值 
			cnt ++;//边数加一 
		} 
 	} 
 	
 	if(cnt < n - 1) return INF;
 	else return res;	
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i ++ )
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = {a, b, w};
	}
	
	int t = kruskal();
	
	if(t == INF) puts("impossible");
	else printf("%d", t);
	
	return 0;
}
