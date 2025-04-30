#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int w[N], s[N];
vector<int> e[N];
int n, k;

void dfs(int now, int fa)
{
	for(auto u : e[now])
	{
		if(u == fa) continue;
		s[u] = s[now] + 1;
		dfs(u, now);
	}
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> w[i];
	}
	
	for(int i = 1; i <= n - 1; i ++ )
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	dfs(1, 0);
	LL ans = 0;
	for(int i = 1; i <= n; i ++ )
	{
		if(s[i] <= 2 * k) ans += w[i];
	}
	cout << ans << endl;
	
	return 0;
}
