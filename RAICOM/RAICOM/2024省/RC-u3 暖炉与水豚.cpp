#include<iostream>
#include<cstring>

using namespace std;

const int N = 1010;
char g[N][N];
bool st[N][N];
int n, m;

//���Ͽ�ʼ,ƫ���� 
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool check_cold(int a, int b)
{
	int x = 0, y = 0;
	for(int i = 0; i < 8; i ++ )
	{
		x = a + dx[i];
		y = b + dy[i];
		//ƫ�ƺ������
		if(x >= 1 && x <= n && y >= 1 && y <= m)
		{
			if(g[x][y] == 'c') return true;//��Χ���䣬����ѡ 
		} 
	}
	return false;//����,��ѡ 
}

void check(int a, int b)
{
	bool flag = false;
	int x = 0, y = 0;
	for(int i = 0; i < 8; i ++ )
	{
		x = a + dx[i];
		y = b + dy[i];
		//ƫ�ƺ������
		if(x >= 1 && x <= n && y >= 1 && y <= m)
		{
			if(g[x][y] == 'm') flag = true;//�ҵ�ů¯ 
		} 
	}
	
	if(!flag)//û�ҵ�ů¯����Χ���ܲ���ů¯ 
	{
		for(int i = 0; i < 8; i ++ )
		{
			x = a + dx[i];
			y = b + dy[i];
			//ƫ�ƺ������
			if(x >= 1 && x <= n && y >= 1 && y <= m)
			{
				if(g[x][y] == '.' && !check_cold(x, y)) st[x][y] = true;//��¼���� 
			} 
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
			cin >> g[i][j];
			
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
			if(g[i][j] == 'w')//ů�� 
				check(i, j);	   
	
	bool flag = false;//�ҵ�û�в������� 
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
			if(st[i][j])
			{
				cout << i << " " << j << endl;	
				flag = true;
			}
	
	if(!flag) cout << "Too cold!" << endl; 
	
	return 0;
}
