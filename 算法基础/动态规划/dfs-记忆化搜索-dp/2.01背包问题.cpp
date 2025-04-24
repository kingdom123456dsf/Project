#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;
int v[N], w[N], mem[N][N];//�������ֵ 
int f[N][N];
int n, m;//��Ʒ�����������ݻ�

int dfs(int u, int spV)//�ڼ�����Ʒ��ʣ����� 
{
	if(mem[u][spV]) return mem[u][spV];
	
	if(u > n) mem[u][spV] = 0;
	else if(spV - v[u] >= 0) mem[u][spV] = max(dfs(u + 1, spV - v[u]) + w[u], dfs(u + 1, spV));//ѡ��ѡ
	else if(spV - v[u] < 0) mem[u][spV] = dfs(u + 1, spV);//��ѡ 
	
	return mem[u][spV];
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 0; j <= m; j ++)
		{
			if(j - v[i] < 0 ) f[i][j] = f[i - 1][j]; 
			else f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
		}
	}
	
	cout << f[n][m] << endl;
	
	return 0;
} 
