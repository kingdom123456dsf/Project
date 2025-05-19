#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510, M = 100010;

struct Edge{
	int a, b, w;
}edges[M];//M���� 

int dist[N], backup[N];
int n, m, k;

void bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for(int i = 0; i < k; i ++ )//��ྭ��k�� 
	{
		memcpy(backup, dist, sizeof dist);//���ݣ���ֹ���� 
		for(int j = 0; j < m; j ++ )//�� 
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
	
	//��Ϊ�����и�Ȩ�ߣ����Բ��������·����ֵ���ܱ�������С 
	if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
	else cout << dist[n] << endl;	
	
	return 0;
}
