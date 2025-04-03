#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 300010;
LL a[N];
int T, n;

int main()
{
	cin >> T;
	while(T -- )
	{
		cin >> n;
		
		for(int i = 0; i < n; i ++ ) cin >> a[i];
		
		for(int i = 0; i < n; i ++ )
		{
			if(a[i] < 0 && i != 0 && i != n - 1)
			{
				LL temp = a[i];
				a[i] -= 2 * temp;
				a[i - 1] += temp, a[i + 1] += temp;
			}
		}
		
		LL res = 0;
		for(int i = 0; i < n; i ++ )
		{
			res = max(res, a[i]);
		}
		
		cout << res << endl;
		
	}
	
	
	return 0;
}
