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
	f[u][1] = happy[u];//��ǰ��ѡ
	
 	//��������
	for(int i = h[u]; i != -1; i = ne[i])//ָ�� 
	{
	 	int j = e[i];//���
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
	while(has_fa[root]) root ++;//�ҵ����ڵ� 
	
	dfs(root);
	
	cout << max(f[root][0], f[root][1]);
	
	return 0;
}
