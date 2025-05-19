#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int n, m;
int p[N];//���ڲ��鼯 (��)

struct Edge{
	int a, b, w;
//	bool operator< (const Edge &W)const
//	{
//		return w < W.w;
//	} 
}edges[N * 2];

int find(int x)//�ϲ����� 
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
	
	for(int i = 1; i <= n; i ++ ) p[i] = i;//��ʼ�����鼯
	
	int res = 0, cnt = 0;//��¼����ͱ��� 
	for(int i = 0; i < m; i ++ )
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		
		a = find(a), b = find(b);//�ҵ����ڵ�
		if(a != b)
		{
			p[a] = b;//�ϲ� 
			res += w;//�𰸼���Ȩֵ 
			cnt ++;//������һ 
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
