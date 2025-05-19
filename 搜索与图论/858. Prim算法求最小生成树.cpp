#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];//����ͼ���ڽӾ���
int dist[N];
bool st[N];

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	
	int res = 0;//�洢�ߺ� 
	for(int i = 0; i < n; i ++ )
	{
		int t = -1;
		for(int j = 1; j <= n; j ++ )
			if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
			
		//�����ǵ�һ�����Ҹ��µĵ�ľ����������� 
		if(i && dist[t] == INF) return INF;
		
		if(i) res += dist[t];//���Ǹ��ڵ�Ϳ��Լ��ϱ߾�����
		st[t] = true; 	
		
		for(int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);//���µ㵽���ϵ���̾��� 
	}	
	
	return res;
}

int main()
{
	memset(g, 0x3f, sizeof g);//��ʼ���ڽӾ��� 
	
	scanf("%d%d", &n, &m);
	while(m -- )
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);//����ͼ��������ֵ���� 
	}
	
	int t = prim();
	
	if(t == INF) puts("impossible");
	else printf("%d", t);
	
	return 0;
}
