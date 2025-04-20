#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
LL a[N], cnt[N];

int main()
{
	int n, k;
	cin >> n >> k;
	
	LL res = 0;
	cnt[0] = 1;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		a[i] += a[i - 1];//处理前缀和 
		
		res += cnt[a[i] % k];
		cnt[a[i] % k] ++ ;
	}
	
	cout << res << endl;
	
	return 0;
}
