#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e5 + 10;
int a[N], cnt[1 << 21];

int main()
{
	int n;
	cin >> n;
	
	cnt[a[0]] = 1;
	long long res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		a[i] ^= a[i - 1];
		res += cnt[a[i]];
		cnt[a[i]] ++ ;
	}
	
	cout << res << endl;
	
	return 0;
}
