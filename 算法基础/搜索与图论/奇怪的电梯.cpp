#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int N = 210;
int g[N];
int n, a, b;
int d[N];

int bfs()
{
	queue<int> q;
	q.push(a);
	
	memset(d, -1, sizeof d);
	d[a] = 0;//Æðµã
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		
		if(t == b) return d[t];
		
		if(t + g[t] <= n && d[t + g[t]] < 0)
		{
			int x = t + g[t];
			d[x] = d[t] + 1;
			q.push(x);
		}
		
		if(t - g[t] >= 1 && d[t - g[t]] < 0)
		{
			int x = t - g[t];
			d[x] = d[t] + 1;
			q.push(x);
		}
	} 
	
	return -1;	
}

int main()
{
	cin >> n >> a >> b;
	
	for(int i = 1; i <= n; i ++ ) cin >> g[i];
	
	cout << bfs() << endl;
	
	return 0;
}
