#include<iostream>
#include<cstdio>

using namespace std;

const int N = 10;
int path[N];
bool st[N];
int n;

void dfs(int u)
{
	if(u == n)//走到最底层 
	{
		for(int i = 0; i < n; i ++ )//因为u是从0开始的
		{
			printf("%d ", path[i]);
		}
		puts("");//换行 
		return;
	}
	
	//否则就往下层走
	for(int i = 1; i <= n; i ++ )//因为数是从1到n
	{
		if(!st[i])//没用过 
		{
			path[u] = i;
			st[i] = true;
			
			dfs(u + 1);
			//每一次调用之后别忘了恢复现场
			st[i] = false; 
		}
	} 
}

int main()
{
	cin >> n;
	
	dfs(0);	
	
	return 0;
}
