#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;
int g[N][N], f[N];
int n;

int main()
{
	cin >> n;
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= i; j ++ )
		{
			cin >> g[i][j];
		}
	}
	
	for(int i = n; i >= 1; i -- )
	{
		for(int j = 1; j <= i; j ++ )
		{
			f[j] = max(f[j + 1], f[j]) + g[i][j];
		}
	}
	cout << f[1] << endl;
	
	return 0;
}
