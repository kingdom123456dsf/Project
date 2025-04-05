#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int T, n;
const int N = 15;
bool st[N];

struct plane{
	int t, d, l;//µ½´ï£¬ÅÌÐý£¬½µÂä 
}p[N];

bool dfs(int u, int last)
{
	if(u == n) return true;
	
	for(int i = 0; i < n; i ++ )
	{
		auto q = p[i];
		if(!st[i] && q.t + q.d >= last)
		{
			st[i] = true;
			
			if(dfs(u + 1, max(last, q.t) + q.l)) return true;
			
			st[i] = false;
		}
	}
	
	return false;
}

int main()
{
	scanf("%d", &T);
	while(T -- )
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i ++ )
		{
			int t, d, l;
			scanf("%d%d%d", &t, &d, &l);
			p[i].t = t, p[i].d = d, p[i].l = l;
		}
		
		memset(st, false, sizeof st);
		
		if(dfs(0, 0)) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
