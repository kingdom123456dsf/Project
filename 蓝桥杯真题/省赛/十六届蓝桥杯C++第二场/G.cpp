#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long LL;

const int N = 1010;
char g[N][N];
int n, m;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//上右下左 

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
	{
		string s;
		cin >> s;
		for(int j = 1; j <= m; j ++ )
		{
			g[i][j] = s[j - 1];//读入输入的一串到数组中去 
		}
	}

	LL ans = 0;//记录最大的答案 
	for(int k = 1; k <= n; k ++ )//要翻转多少次行
	{
		LL res = 0;//其中一种方案的答案 
		for(int i = 1; i <= n; i ++ )
		{
			for(int j = 1; j <= m; j ++ )
			{
				int cnt = 0;//相同的个数 
				for(int d = 0; d < 4; d ++ )//查看上右下左有几个相同的 
				{
					int x = i + dx[d], y = j + dy[d];
					if(x > 0 && x <= n && y > 0 && y <= m)
					{
						if(g[i][j] == g[x][y]) cnt ++;
					}
				}
				res += (LL)cnt * cnt;
			}
		}
		ans = max(ans, res);
		
		for(int j = 1; j <= n; j ++ )//翻转行 
		{
			if(g[k][j] == '1') g[k][j] = '0';
			else g[k][j] = '1';
		}
	}
	
	//最后一行翻转完没有统计
	LL res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
		{
			int cnt = 0;//相同的个数 
			for(int d = 0; d < 4; d ++ )//查看上右下左有几个相同的 
			{
				int x = i + dx[d], y = j + dy[d];
				if(x > 0 && x <= n && y > 0 && y <= m)
				{
					if(g[i][j] == g[x][y]) cnt ++;
				}
			}
			res += (LL)cnt * cnt;
		}
	}
	ans = max(ans, res); 
	
	cout << ans << endl;
	
	return 0;
}
