#include<iostream>
#include<cstdio>

using namespace std;

const int N = 20;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];//列，主对角线，斜对角线
int n;

void dfs(int x, int y, int s)
{
	if(y == n) y = 0, x ++;//当前行的列走到头了,给换到下一行的第一位
	
	if(x == n)//行走完了
	{
	    if(s == n)//皇后也放完了
	    {
	        for(int i = 0; i < n; i ++ ) puts(g[i]);
	        puts("");
	    }
	}
	
	dfs(x, y + 1, s);//当前格子不放皇后,直接去当前行的下一列
	
	for(int i = 0; i < n; i ++ )
	{
	    if(!row[i] && !col[i] && !dg[x + y] && !udg[n + x - y])//符合题意
	    {
	        g[x][y] = 'Q';
	        row[i] = col[i] = dg[x + y] = udg[n + x - y] = true;
	        dfs(x, y + 1, s + 1);
	        //恢复现场
	        row[i] = col[i] = dg[x + y] = udg[n + x - y] = false;
	        g[x][y] = '.';
	    }
	}
}

int main()
{
	
	cin >> n;
	for(int i = 0; i < n; i ++ )
		for(int j = 0; j < n; j ++ )
			g[i][j] = '.';//初始化 
		
	dfs(0, 0, 0); 
	
	return 0;
} 
