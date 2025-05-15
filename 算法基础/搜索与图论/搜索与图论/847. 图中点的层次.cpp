#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], idx;
int n, m;
int d[N], q[N];//距离 

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++ ;
}

int bfs()
{
	memset(d, -1, sizeof d);
	
	q[0] = 1;
	
	d[1] = 0; 
	
	int hh = 0, tt = 0;
	while(hh <= tt)
	{
		int t = q[hh ++ ];
		
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];//可以到的点 
			if(d[j] == -1)
			{
				d[j] = d[t] + 1;
				q[ ++ tt] = j;
			}
		}
	}
	
	return d[n];
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
	}
	 	
	cout << bfs() << endl;
	
	return 0;
}
