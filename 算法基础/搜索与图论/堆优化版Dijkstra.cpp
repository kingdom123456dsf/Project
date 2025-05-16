#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1500010;
int h[N], e[N], ne[N], w[N], idx;//��ӱ�洢��w�洢Ȩ�� 
int dist[N];//��¼1~n�����·�� 
bool st[N];
int n, m;

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);//�Ƚ������ʼ��Ϊ������ 

    dist[1] = 0;//�����ǣ����� 
	
	//ע��һ��Ҫ�����롢�����洢����ΪС�����ȸ��ݾ������� 
	priority_queue<PII, vector<PII>, greater<PII>> heap;//�洢(����,��) 
    heap.push({0, 1});//��һ�������Ϊ0
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		
		int ver = t.second, distance = t.first;
		
		if(st[ver]) continue;
		st[ver] = true;
		
		for(int i = h[ver]; i != -1; i = ne[i])//������ӱ��ٱ� 
		{
			int j = e[i];//�õ��� 
			if(dist[j] > distance + w[i]) 
			{
				dist[j] = distance + w[i];
				heap.push({dist[j], j}); 
			}
		}
	} 

    //����1~n�ľ��뻹�������֤��1~n�����· 
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];	
} 

int main()
{
	memset(h, -1, sizeof h);//��ӱ��ʼ�� 
	
    scanf("%d%d", &n, &m);
    while(m -- )
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add(x, y, w);
    }

    printf("%d", dijkstra());

    return 0;
}
