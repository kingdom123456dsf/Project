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
int pre[N][N];//新增一个数组记录从哪个方向走来的 

//下、左、右、上 DLRU 
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};

void bfs(int x, int y)
{
	st[0][0] = true;
	q.push({0, 0});
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		
		for(int i = 0; i < 4; i ++ )
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			if(a >= 0 && a < 30 && b >= 0 && b < 50 && !st[a][b] && g[a][b] == 0)
			{
				st[a][b] = true;
				pre[a][b] = i;//记录从哪个方向走来的 
				q.push({a, b});
			}
		}
	}
	
	//回溯路径
	int a = 29, b = 49;
	while(a != 0 || b != 0)
	{
		int d = pre[a][b];
		path += dir[d];
		a -= dx[d];
		b -= dy[d];
	}
	reverse(path.begin(), path.end());//因为是从后往前存的 	
}

int main()
{
	for(int i = 0; i < 30; i ++ )
	{
		for(int j = 0; j < 50; j ++ )
		{
			char c; 
			cin >> c;
			g[i][j] = c - '0';
		}
	}
	puts("");
	
	bfs(0, 0);
	
	cout << path << endl; 
	
	return 0;
}
