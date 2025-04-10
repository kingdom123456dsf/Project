#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
LL a[N * 2];

int main()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < 2 * n; i ++ )
	{
		cin >> a[i];
	}
	
	sort(a, a + 2 * n);
	
	LL res = 0;
	for(int i = 0; i < n; i ++ )
	{
		res += a[i] * a[2 * n - i - 1];
	}
	
	cout << res << endl;
	
	return 0;
}
