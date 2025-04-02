#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
long long a[N];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	long long res = 0;
	for(int i = 1; i <= n - 1; i ++ )
	{
		res += a[i] * (n - i);
	}
	
	cout << res << endl;
	
	return 0;
}
