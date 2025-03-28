#include<iostream>
#include<cstring>

using namespace std;

const int N = 11;
int g[N][N];//四维数组用来存储两个点坐标(x1,y1,x2,y2) 
bool st[N][N], diag[N][N][N][N];//检查点是否用过
int n, k; 
string path;
bool found;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int x, int y)
{
	if(x == n - 1 && y == n - 1)//判断是否每一格都走过 
	{
		if(path.size() == n * n - 1) found = true;
		return;
	}
	st[x][y] = true;//对称着来写
	
	for(int i = 0; i < 8;  i ++ )//因为是从小到大枚举的，所以第一条路径一定是字典序最小的那一条 
	{
		int a = x + dx[i], b = y + dy[i];
		
		if(a < 0 || a >= n || b < 0 || b >= n) continue;
		
		if(g[a][b] != (g[x][y] + 1) % k) continue;
		
		if(st[a][b]) continue;
		
		if(i % 2 && (diag[x][b][a][y] || diag[a][y][x][b])) continue;//因为对角线的偏移量位置是奇数 
		
		diag[x][y][a][b] = true;//对称着来写 
		path += i + '0';
		
		dfs(a, b);
		if(found) return;
		
		path.pop_back();
		diag[x][y][a][b] = false;
	}
	
	st[x][y] = false;//恢复现场 
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i ++ )
	{
		for(int j = 0; j < n; j ++ )
		{
			cin >> g[i][j];
		}
	}
	
	dfs(0, 0);
	if(!found) cout << -1 << endl;
	else cout << path << endl;
	
	return 0;	
} 
