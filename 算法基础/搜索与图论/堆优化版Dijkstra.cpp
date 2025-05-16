#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1500010;
int h[N], e[N], ne[N], w[N], idx;//领接表存储，w存储权重 
int dist[N];//记录1~n的最短路径 
bool st[N];
int n, m;

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);//先将距离初始化为正无穷 

    dist[1] = 0;//别忘记！！！ 
	
	//注意一定要按距离、点来存储，因为小根堆先根据距离排序 
	priority_queue<PII, vector<PII>, greater<PII>> heap;//存储(距离,点) 
    heap.push({0, 1});//第一个点距离为0
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		
		int ver = t.second, distance = t.first;
		
		if(st[ver]) continue;
		st[ver] = true;
		
		for(int i = h[ver]; i != -1; i = ne[i])//遍历领接表，临边 
		{
			int j = e[i];//得到点 
			if(dist[j] > distance + w[i]) 
			{
				dist[j] = distance + w[i];
				heap.push({dist[j], j}); 
			}
		}
	} 

    //若是1~n的距离还是正无穷，证明1~n无最短路 
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];	
} 

int main()
{
	memset(h, -1, sizeof h);//领接表初始化 
	
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
