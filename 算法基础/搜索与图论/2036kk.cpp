#include<iostream>
#include<algorithm>

using namespace std;

const int N = 20;
int s[N], b[N];
bool st[N];
int res = 1e9;
int n;

void dfs(int u)
{
	if(u > n)
	{
		int suan = 1, ku = 0;
		bool flag = false;
		for(int i = 1; i <= n; i ++ )
		{
			if(st[i])
			{
				suan *= s[i];
				ku += b[i];
				flag = true;//至少选一个 
			}
		}
		if(flag) res = min(res, (abs(suan - ku)));
		return ;
	}
	
	st[u] = true;
	dfs(u + 1);
	st[u] = false;
	
	dfs(u + 1);//不选 
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> s[i] >> b[i];
	}
	
	dfs(1);
	
	cout << res << endl;
   
    return 0;
}
