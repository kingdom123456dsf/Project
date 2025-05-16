#include<iostream>

using namespace std;

const int N = 1010;

int a[N][N], b[N][N];
int n, m, q;

//差分矩阵的添加操作 
void insert(int x1, int y1, int x2, int y2, int c)
{
	b[x1][y1] += c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

int main()
{
	cin >> n >> m >> q;
	for(int i = 1; i <= n ; i++ )
		for(int j = 1; j <= m ; j ++ )
			cin >> a[i][j];
			
	//初始化差分矩阵可以直接看 给1 * 1的矩阵插入数 
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
			insert(i, j, i, j, a[i][j]);		
	
	while(q -- )
	{
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}
	
	//还原回原矩阵，其实就是求前缀和的过程 
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
		{
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
			cout << b[i][j] << " ";
		}
		puts("");
	}
	
	return 0;
}
