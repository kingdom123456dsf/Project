#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long LL;

LL a[1000001];

int main()
{
	LL n, k;
	cin >> n >> k;
	
	for(LL i = 1; i < n; i ++ )
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	
	if(k >= n - 1)
	{
		cout << 0 << endl;
	}
	else
	{
		LL res = 0;
		for(LL i = 1; i + k <= n; i ++ )
		{
			res = max(res, a[i + k - 1] - a[i - 1]);
		}
		cout << a[n - 1] - res << endl;
	}
	
	return 0;
}
