#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1010;
LL a[N][N];

int main()
{
	int n, m, c;
	cin >> n >> m >> c;
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
		{
			cin >> a[i][j];
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];  
		}
	}
	
	LL res = 0, maxx = 0, maxy = 0;
	for(int i = 1; i + c - 1 <= n; i ++ )
	{
		for(int j = 1; j + c - 1 <= m; j ++ )
		{
	 	 	LL tmp = a[i + c - 1][j + c - 1] - a[i - 1][j + c - 1] - a[i + c - 1][j - 1] + a[i - 1][j - 1];
	 	 	if(tmp > res)
	 	 	{
	 	 		res = tmp;
	 	 		maxx = i, maxy = j;
			}
		}
	}
	
	cout << maxx << " " << maxy << endl;
	
	return 0;
}
