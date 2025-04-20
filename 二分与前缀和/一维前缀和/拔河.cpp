#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 1010;
LL a[N];
vector<LL> res;

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	
	for(int i = 1; i <= n; i ++ )
	{
		int j = i;
		while(j <= n)
		{
			res.push_back(a[j] - a[i - 1]);
			j ++;
		}
	}
	
	sort(res.begin(), res.end());
	LL ans = 1e17;
	for(int i = 1; i < res.size(); i ++ )
	{
		ans = min(ans, res[i] - res[i - 1]);
	}
	
	cout << ans << endl;
	
	return 0;
}
