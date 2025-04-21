#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e5 + 10;
int f[N], h[N];
int n;

int main()
{
	int t;
	cin >> t;
	while(t -- )
	{
		cin >> n;
		for(int i = 1; i <= n; i ++ )
		{
			cin >> h[i];
		}
		
		int newf = 0, tmp1 = 0, tmp2 = 0;
		for(int i = 1; i <= n; i ++ )
		{
			newf = max(tmp1, tmp2 + h[i]);
			tmp2 = tmp1;
			tmp1 = newf;
		}
		cout << newf << endl;
	}
		
	return 0;
}
