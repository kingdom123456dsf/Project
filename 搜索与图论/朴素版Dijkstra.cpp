#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 510;//��
int g[N][N];//�洢Ȩ��
int dist[N];//��¼1~n�����·�� 
bool st[N];//��¼ÿ�����Ƿ������· 
int n, m;//�㣬��

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);//�Ƚ������ʼ��Ϊ������ 
	
	dist[1] = 0;//�����ǣ����� 
	
	for(int i = 0; i < n; i ++ )//��n���㣬����n�� 
	{
		int t = -1;
		for(int j = 1; j <= n; j ++ )
		{
			//�ҵ���ǰ������·��
			if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j; 
		}
		
		st[t] = true;//1~t�����·�Ѿ����� 
		
		for(int j = 1; j <= n; j ++ )
		{
			dist[j] = min(dist[j], dist[t] + g[t][j]);//1��j �� 1��t��j����Сֵ 
		}
	}
	
	//����1~n�ľ��뻹�������֤��1~n�����· 
	if(dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];	
} 

int main()
{
 	scanf("%d%d", &n, &m);
 	
 	memset(g, 0x3f, sizeof g);//����ľ����ʼ��Ϊ������
	
	while(m -- )
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		
		g[x][y] = min(g[x][y], w);
	}
 	
	printf("%d", dijkstra());
	  
	return 0;
}
