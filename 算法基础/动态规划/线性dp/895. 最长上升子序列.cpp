#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;
int n;

int dfs(int u, int len)
{
	if(u > n) return 0;
	
	if(g[u + 1] > len) return max(1 + dfs(u + 1, g[u + 1]), dfs(u + 1, len));
	else return dfs(u + 1, len);
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> g[i];

	cout << dfs(0, -1e9) << endl;
	
	return 0;
}
