#include<iostream>

using namespace std;

typedef long long LL;

const int N = 510;
int a[N][N];
int n, m, k;

int main()
{
	cin >> n >> m >> k;//小于等于k
	for(int i = 1; i <= n; i++)
	{
	 	for(int j = 1; j <= m; j++)
	 	{
	 		cin >> a[i][j];
	 		a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];//前缀和 
		}
	} 
	
	
//	int res = 0;
//	for(int x1 = 1; x1 <= n; x1++)
//	{
//	 	for(int y1 = 1; y1 <= m; y1++)
//	 	{
//	 		for(int x2 = 1; x2 <= x1; x2++)
//	 		{
//	 			for(int y2 = 1; y2 <= y1; y2++)
//	 			{
//	 				int tmp = s[x1][y1] - s[x2 - 1][y1] - s[x1][y2 - 1] + s[x2 - 1][y2 -1];
//	 				if(tmp <= k) res++;
//				}
//			}
//		}
//	} 

	LL ans = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = i; j <= m; j++)
		{
			for(int s = 1, t = 1; t <= n; t++)
			{
				while(s <= t && a[t][j] - a[s - 1][j] - a[t][i - 1] + a[s - 1][i - 1] > k) s++;
				if(s <= t) ans += t - s + 1;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
