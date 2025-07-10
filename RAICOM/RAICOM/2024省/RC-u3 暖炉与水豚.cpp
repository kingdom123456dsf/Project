#include<iostream>
#include<cstring>

using namespace std;

const int N = 1010;
char g[N][N];
bool st[N][N];
int n, m;

//从上开始,偏移量 
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool check_cold(int a, int b)
{
	int x = 0, y = 0;
	for(int i = 0; i < 8; i ++ )
	{
		x = a + dx[i];
		y = b + dy[i];
		//偏移后的坐标
		if(x >= 1 && x <= n && y >= 1 && y <= m)
		{
			if(g[x][y] == 'c') return true;//周围有冷，不可选 
		} 
	}
	return false;//无冷,可选 
}

void check(int a, int b)
{
	bool flag = false;
	int x = 0, y = 0;
	for(int i = 0; i < 8; i ++ )
	{
		x = a + dx[i];
		y = b + dy[i];
		//偏移后的坐标
		if(x >= 1 && x <= n && y >= 1 && y <= m)
		{
			if(g[x][y] == 'm') flag = true;//找到暖炉 
		} 
	}
	
	if(!flag)//没找到暖炉，周围可能藏了暖炉 
	{
		for(int i = 0; i < 8; i ++ )
		{
			x = a + dx[i];
			y = b + dy[i];
			//偏移后的坐标
			if(x >= 1 && x <= n && y >= 1 && y <= m)
			{
				if(g[x][y] == '.' && !check_cold(x, y)) st[x][y] = true;//记录坐标 
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
			if(g[i][j] == 'w')//暖的 
				check(i, j);	   
	
	bool flag = false;//找到没有藏匿的情况 
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
