#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 6010;
int h[N], e[N], ne[N], idx;//邻接表建图,队头,当前元素值,指针域 
int happy[N];//高兴度 
int f[N][2];//状态表示0/1选不选当前节点
bool has_fa[N];//是否有父节点,相当于找根节点 

void add(int a, int b)//建图,在a后插入b 
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{
	f[u][1] = happy[u];//当前选
	
	for(int i = h[u]; i != -1; i = ne[i])//遍历子节点 
	{
		int j = e[i];
		dfs(j);//回溯
		
		f[u][1] += f[j][0];//根节点选，子节点不可选
		f[u][0] += max(f[j][0], f[j][1]); 
	} 
} 

int main()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i ++ ) cin >> happy[i];
	
	memset(h, -1, sizeof h);//将队头初始化
 	
 	for(int i = 1; i <= n - 1; i ++ )
 	{
 		int a, b;
 		cin >> a >> b;//根、父
		add(b, a);//b是父节点 
		has_fa[a] = true;//a有父节点了 
	}
	
	int root = 1;//找到根节点
	while(has_fa[root]) root ++;
	
	dfs(root);//从根节点开始递归
	
	cout << max(f[root][0], f[root][1]);//根节点选或不选 
	
	return 0;
}
