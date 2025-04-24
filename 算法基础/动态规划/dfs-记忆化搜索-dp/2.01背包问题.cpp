#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;
int v[N], w[N], mem[N][N];//体积，价值 
int f[N][N];
int n, m;//物品数量、背包容积

int dfs(int u, int spV)//第几个物品，剩余体积 
{
	if(mem[u][spV]) return mem[u][spV];
	
	if(u > n) mem[u][spV] = 0;
	else if(spV - v[u] >= 0) mem[u][spV] = max(dfs(u + 1, spV - v[u]) + w[u], dfs(u + 1, spV));//选或不选
	else if(spV - v[u] < 0) mem[u][spV] = dfs(u + 1, spV);//不选 
	
	return mem[u][spV];
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 0; j <= m; j ++)
		{
			if(j - v[i] < 0 ) f[i][j] = f[i - 1][j]; 
			else f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
		}
	}
	
	cout << f[n][m] << endl;
	
	return 0;
} 
