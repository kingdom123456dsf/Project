#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[9];

int main()
{
	int n;cin >> n;
	int m = 0;
	for(int i = 0; i < n; i ++ )
	{
		string s; cin >> s;
		int x = s[0] - '0', y = s.back() - '0';
		dp[y] = max(dp[x] + 1, dp[y]);
		m = max(m, dp[y]);
	}
	
	cout << n - m << endl;
		
	return 0;
}
