#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 5002;//注意因为横纵坐标都+1了，所以不能5001会越界

int s[N][N];//优化，直接使用前缀和数组先存储，减少一倍空间占用 
int n, m;//横纵坐标 

int main(){
	int cnt, r;
	cin >> cnt >> r;
	r = min(r,5001);
	
	n = m = r;
	for(int i = 0; i < cnt; i++)
	{
		 int x, y, w;
		 cin >> x >> y >> w;
		 x++,y++;//因为给从（1,1）开始，别忘了给每个坐标加上1
		 n = max(n, x);
		 m = max(m, y);
		 s[x][y] += w;
	}
	
	for(int i = 1; i <= n; i++)//求前缀和 
	{
		for(int j = 1;j <= m; j++)
		{
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	
	int res = 0;
	for(int i = r;i <= n;i++)
	{
		for(int j = r;j <= m; j++)
		{
			res = max(s[i][j] - s[i][j - r] - s[i - r][j] + s[i - r][j - r],res);
		}
	}
	
	cout << res << endl;
	return 0;
}
