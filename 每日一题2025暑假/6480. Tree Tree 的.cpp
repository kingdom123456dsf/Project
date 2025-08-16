#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int N = 11;

set<int> g[N];//自动去重边
int dist[N], d1, d2;//结点，最大和第二大 

void dfs(int u, int distance)
{
	dist[u] = distance;
	
	for(auto v : g[u])//枚举邻接点 
	{
		//走回了走过的点（构成环） 
		if(dist[v])
		{
			int d = dist[u] - dist[v] + 1;//判断有几个结点
			//修改最大和第二大
			if(d > d1) d2 = d1, d1 = d;
			else if(d < d1 && d > d2)  d2 = d; 
		}//构成环了就直接回溯即可 
		else dfs(v, distance + 1);//否则继续枚举 
	}
	
	dist[u] = 0;//恢复现场 
}

int main()
{
	int t;
	cin >> t;
	
	while(t -- )
	{
		int n, m;
		cin >> n >> m;
		
		//清空G
		for(auto& e: g) e.clear(); 
		
		d1 = 1, d2 = 0;//只有一个点时 
		while(m -- )
		{
			int a, b;
			cin >> a >> b;
			if(a == b) continue;//自环不存
			//否则有两个以上的点且连通
			d1 = 2, d2 = 1;
			g[a].insert(b), g[b].insert(a); //自动去重边
		}
		
		//枚举每一个点为起点
		for(int i = 1; i <= n; i ++ ) dfs(i, 1);//结点从1开始 
		
		cout << d1 << ' ' << d2 << endl; 
	}	
	
	return 0;
}
