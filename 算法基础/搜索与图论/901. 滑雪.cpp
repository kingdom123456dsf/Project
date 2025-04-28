#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 310;
int g[N][N];
int d[N][N];
int res;
int n, m;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//иосробвС 

int bfs(int x, int y)
{
	queue<PII> q;
	q.push({x, y});
	
	memset(d, -1, sizeof d);
	d[x][y] = 0;
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		
		for(int i = 0; i <= 3; i ++ )
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			if(a >= 1 && a <= n && b >= 1 && b <= m && d[a][b] < 0)
			{
				d[a][b] = d[t.first][t.second] + 1;
				q.push({a, b});
			}
		}
	}
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
		{
			res = max(res, d[i][j]);
		}
	}
	
	return res;
}

int main()
{
	cin >> n >> m;
	
	int mxy = 0;
	int x = 0, y = 0;
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
		{
			cin >> g[i][j];
			if(g[i][j] > mxy)
			{
				mxy = g[i][j];
				x = i, y = j;
			}
		}
	}
	
	cout << mxy << " " << x << " " << y << endl;
	
	cout << bfs(x, y) << endl;
	
	return 0;
}
