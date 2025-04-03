#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef pair<int, int> PII;

const int N = 60;
int g[N][N]; 
queue<PII> q;//代表坐标
bool st[N][N];//代表每个位置是否走过 
string path;//记录路径 

//下、左、右、上 DLRU 
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};
char ss[4] = {'D', 'L', 'R', 'U'};

void bfs(int x, int y)
{
	st[0][0] = true;
	q.push({0, 0});
	
	while(q.size() > 0)
	{
		auto t = q.front(); q.pop();
		
		for(int i = 0; i < 4; i ++ )
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			if(a >= 0 && a < 4 && b >= 0 && b < 6 && !st[a][b] && g[a][b] == 0)
			{
				st[a][b] = true;
				path += ss[i];
				
				q.push({a, b});
			}
		}
	}
 	
}

int main()
{
	for(int i = 0; i < 4; i ++ )
	{
		for(int j = 0; j < 6; j ++ )
		{
			char c; 
			cin >> c;
			g[i][j] = c - '0';
		}
	}
	puts("");
	
	st[0][0] = true;
	dfs(0, 0);
//	bfs(0, 0);
	
	cout << path << endl; 
	
	for(int i = 0; i < 4; i ++ )
	{
		for(int j = 0; j < 6; j ++ )
		{
			cout << g[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
