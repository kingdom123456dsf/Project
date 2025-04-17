#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 6010;
int e[N], ne[N], h[N], idx;
int happy[N];
bool has_fa[N]; 
int f[N][2];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++; 
}

void dfs(int u)
{
	f[u][1] = happy[u];//当前根选
	
 	//遍历子树
	for(int i = h[u]; i != -1; i = ne[i])//指针 
	{
	 	int j = e[i];//结点
		dfs(j);
		
		f[u][1] += f[j][0]; 
		f[u][0] += max(f[j][1], f[j][0]);
  	} 
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n ; i ++ ) cin >> happy[i];
	
	memset(h, -1, sizeof h);
	
	for(int i = 1; i <= n - 1; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(b, a);
		has_fa[a] = true;
	}
	
	int root = 1;
	while(has_fa[root]) root ++;//找到根节点 
	
	dfs(root);
	
	cout << max(f[root][0], f[root][1]);
	
	return 0;
}
