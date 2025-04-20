#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 2e6 + 10;
int a[N], b[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
	{
		int x;
		cin >> x;
		if(x > 0) a[x] += 1;
		else if(x == 0) a[0] = b[0] = 1;
		else b[-1 * x] += 1;//都变成正的 
	}
	
	for(int i = 1; i <= m; i ++ )
	{
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}
	
	int ans = 0;
	for(int i = 0; i <= m; i ++ )
	{
		ans = max(ans, max(a[i] + b[(m - 2 * i) >= 0 ? (m - 2 * i) : 0], b[i] + a[(m - 2 * i) >= 0 ? (m - 2 * i) : 0]));
	}
	
	cout << ans << endl;
	
	return 0;
}
