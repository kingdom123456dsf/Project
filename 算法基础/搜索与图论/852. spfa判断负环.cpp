#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int N = 2010, M = 10010;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];//cnt用来记录到该点的最短路走过几条边
bool st[N];
int n, m; 

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool spfa()
{
	queue<int> q;
	
	//因为有负环的起点可能从任意点开始 
	for(int i = 1; i <= n; i ++ )
	{
		q.push(i);
		st[i] = true;//代表有这个点了 
	}
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		
		st[t] = false;
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];//可以到的点
			
			if(dist[j] > dist[t] + w[i])
			{
				cnt[j] = cnt[t] + 1;//走过的边数
 				dist[j] = dist[t] + w[i];
 				if(cnt[j] >= n) return true;
				if(!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			} 
		}
	}
	
	return false;	
}


int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n >> m;
	for(int i = 0; i < m; i ++ )
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	
	if(spfa()) puts("Yes");
	else puts("No");
	
	return 0;
}
