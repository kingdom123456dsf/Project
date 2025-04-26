#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	long long res = 0;
	for(int i = n; i <= n + 24; i ++ )
	{
		res += i;
	}
	cout << res << endl;	
	
	return 0;
}
