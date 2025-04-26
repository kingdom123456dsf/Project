#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int w[N];
int n, k;

int main()
{
	cin >> n >> k;
	long long res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> w[i];
		res += w[i];
	}
	
	for(int i = 1; i <= n - 1; i ++ )
	{
		int u, v;
		cin >> u >> v;
	}
	
	res -= w[n];
	res -= w[n - 1];
	cout << res << endl;
	
	return 0;
}
