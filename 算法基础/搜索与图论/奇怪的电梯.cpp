#include<iostream>
#include<cstring> 

using namespace std;

const int N = 210;
int g[N], mem[N];
int n, a, b;
int res = 1e9;

void dfs(int u, int step)
{
	mem[u] = step;//记录走到当前层数的步数，若是以更多步数到达当前层，则代表不能走到目标层 
	
	if(u == b)
	{
		res = min(res, step);
	}
	
	if(u - g[u] >= 1 && step + 1 < mem[u - g[u]])
	{
		dfs(u - g[u], step + 1);
	}
	
	if(u + g[u] <= n && step + 1 < mem[u + g[u]])
	{
		dfs(u + g[u], step + 1);
	}
	
}

int main()
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i ++ ) cin >> g[i];
	
	memset(mem, 0x3f, sizeof mem);
	dfs(a, 0);
	
	if(res == 1e9) cout << -1 << endl;
	else cout << res << endl;
	
	return 0;
}
