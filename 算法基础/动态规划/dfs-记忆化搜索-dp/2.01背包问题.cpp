#include<iostream>
#include<cstring>

using namespace std;

const int N = 10010;
int v[N], w[N], mem[N][N], f[N];
int n, maxv;

int dfs(int u, int spV)//第几个物品，剩余可选体积 
{
	if(mem[u][spV]) return mem[u][spV];
	
	if(u > n) mem[u][spV] = 0;
	else if(spV < v[u]) mem[u][spV] = dfs(u + 1, spV);//因为剩余体积不够选
	else if(spV >= v[u]) mem[u][spV] = max(dfs(u + 1, spV - v[u]) + w[u], dfs(u + 1, spV));//也分选和不选两种情况
	
	return mem[u][spV]; 
}

int main()
{
	cin >> n >> maxv;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> v[i] >> w[i];
	}
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = maxv; j >= 0; j -- )
		{
			if(j < v[i]) f[j] = f[j];
			else f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << f[maxv]; 	
	
	return 0;
}
