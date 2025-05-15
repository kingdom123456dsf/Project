#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], idx;
int d[N], ans[N];//d记录入度,q模拟队列 
int n, m;

void add(int a, int b)//领接表 
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++ ;
} 

bool topsort()
{
	queue<int> q;
	for(int i = 1; i <= n; i ++ )
	{
		if(!d[i]) q.push(i);//将起点放入队列 
 	}
 	
 	int cnt = 0;
 	while(q.size())
 	{
 		auto t = q.front();q.pop();//q其实就是满足条件的拓扑序列 
 		ans[cnt ++ ] = t;//这个t其实就是拓扑序列 
 		
 		for(int i = h[t]; i != -1; i = ne[i])
 		{
 			int j = e[i];
 			d[j] -- ;
 			if(!d[j]) q.push(j);//又有新的起点了 
		}
	}
	
	return cnt == n;//所有点都可以 
}

int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b] ++ ;//b点的入度多1 
	}
	
	if(topsort())
	{
		for(int i = 0; i <= n - 1; i ++ )
		{
			cout << ans[i] << " ";
		}
	}
	else puts("-1");
	
	
	return 0;
}
