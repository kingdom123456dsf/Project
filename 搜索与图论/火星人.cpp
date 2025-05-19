#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N]; 
int state[N];
bool st[N];
int n, m;//手指数，要加的
int sum = 0;

void dfs(int u)
{
	if(u > n)
	{
		++ sum;
		if(sum > m)
		{
			for(int i = 1; i <= n; i ++ )
			{
				cout << state[i] << " ";
			}
			exit(0);
		}
		return ;
	}
	
	if(!sum)
	{
		for(int i = a[u]; i <= n; i ++ )
		{
			if(!st[i])
			{
				st[i] = true;
				state[u] = i;
				
				dfs(u + 1);
				
				state[u] = 0;
				st[i] = false;			
			}
		}
	}
	else
	{
		for(int i = 1; i <= n; i ++ )
		{
			if(!st[i])
			{
				st[i] = true;
				state[u] = i;
				
				dfs(u + 1);
				
				state[u] = 0;
				st[i] = false;			
			}
		}
	}
	
}

int main()
{
 	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
	}
	
	dfs(1);
	
	return 0;
}
