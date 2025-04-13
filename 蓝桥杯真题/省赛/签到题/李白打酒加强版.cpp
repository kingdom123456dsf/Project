#include<iostream>

using namespace std;

const int MOD = 1000000007;
int ans;
int n, m;

void dfs(int u, int i, int j, int st)//酒店花 
{
	if(u == 0 && i == 0 && j == 0 && st == 1)
	{
		ans = (ans + 1) % MOD;
	}
	
	if(u < 0 || i < 0 || j < 0) return;//不合法，返回
	
	//店 
 	if(i > 0) dfs(u * 2, i - 1, j, 0);
 	//花 
 	if(u > 0 && j > 0) dfs(u - 1, i, j - 1, 1);
}

int main()
{
	cin >> n >> m;
	
	dfs(2, n, m, -2);//酒，店，花，(0/1,店或花) 
	
	cout << ans << endl;
	
	return 0;
}
