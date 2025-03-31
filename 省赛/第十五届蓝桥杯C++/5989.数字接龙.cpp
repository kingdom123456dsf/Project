#include<iostream>
#include<cstring>

using namespace std;

const int N = 11;
int g[N][N];//��ά���������洢����������(x1,y1,x2,y2) 
bool st[N][N], diag[N][N][N][N];//�����Ƿ��ù�
int n, k; 
string path;
bool found;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int x, int y)
{
	if(x == n - 1 && y == n - 1)//�ж��Ƿ�ÿһ���߹� 
	{
		if(path.size() == n * n - 1) found = true;
		return;
	}
	st[x][y] = true;//�Գ�����д
	
	for(int i = 0; i < 8;  i ++ )//��Ϊ�Ǵ�С����ö�ٵģ����Ե�һ��·��һ�����ֵ�����С����һ�� 
	{
		int a = x + dx[i], b = y + dy[i];
		
		if(a < 0 || a >= n || b < 0 || b >= n) continue;
		
		if(g[a][b] != (g[x][y] + 1) % k) continue;
		
		if(st[a][b]) continue;
		
		if(i % 2 && (diag[x][b][a][y] || diag[a][y][x][b])) continue;//��Ϊ�Խ��ߵ�ƫ����λ�������� 
		
		diag[x][y][a][b] = true;//�Գ�����д 
		path += i + '0';
		
		dfs(a, b);
		if(found) return;
		
		path.pop_back();
		diag[x][y][a][b] = false;
	}
	
	st[x][y] = false;//�ָ��ֳ� 
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i ++ )
	{
		for(int j = 0; j < n; j ++ )
		{
			cin >> g[i][j];
		}
	}
	
	dfs(0, 0);
	if(!found) cout << -1 << endl;
	else cout << path << endl;
	
	return 0;	
} 
