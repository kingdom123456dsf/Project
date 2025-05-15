#include<iostream>
#include<vector>

using namespace std;

const int N = 15;
int g[N];//调料 
int n;//美味程度 
vector<int> v;

void dfs(int u, int sum)
{
	if(sum > n) return;//剪枝
	 
	if(u > 10)
	{
		if(sum == n)
		{
			for(int i = 1; i <= 10; i ++ )
				v.push_back(g[i]);
		}
		return;
	}
	
	for(int i = 1; i <= 3; i ++ )
	{
		g[u] = i;
		dfs(u + 1, sum + i);
		g[u] = 0;
	}
}

int main()
{
	cin >> n;
	
	dfs(1, 0);//从第一个调料开始
	
	cout << v.size() / 10 << endl;
	for(int i = 0; i < v.size(); i ++ )
	{
		cout << v[i] << " ";
		if((i + 1) % 10 == 0) puts("");
	}
		
	return 0;
}
