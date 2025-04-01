#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct plane{
	int t, d, l;//到达，盘旋，降落 
}; 

const int N = 15;
bool st[N];//表示每架飞机是否降落 
bool flag;//代表是否可以全部降落 
vector<plane> q;
int T;
int n;

void dfs(int u, int last)//第几架飞机，降落时间
{
	if(u == n)
	{
	    flag = true;
	    return;
	}
	
	for(int i = 0; i < n; i ++ )
	{
		if(!st[i] && q[i].t + q[i].d >= last)
		{
			st[i] = true;
			
			dfs(u + 1, max(last, q[i].t) + q[i].l);
			
			st[i] = false;
		}
	}
} 

int main()
{
	cin >> T;
	while(T -- )
	{
		q.erase(q.begin(), q.end());//清空 
		cin >> n;
		for(int i = 0; i < n; i ++ )
		{
			int a, b, c;
			cin >> a >> b >> c;
			q.push_back({a, b, c});
		}
        
        flag = false;
        dfs(0, 0);
			
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	return 0;
}
