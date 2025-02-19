#include<iostream>

using namespace std;

typedef long long LL;

const int N = 500010;
LL s[N];
int T, n;
LL ans1, ans2;

int main()
{
	cin >> T;
	while(T--)
	{ 
		cin >> n;
		for(int i = 1;i <= n;i++) 
		{
			cin >> s[i];
			s[i] = s[i - 1] + s[i];
		}
		
		int l = n / 2 + 1;//A能得到的蛋糕数 
		ans1 = 1e15;
		for(int i = 1;i <= n;i++)
		{
			if(i >= l) ans1 = min(ans1, s[i] - s[i - l]);
		}
	 	
	 	ans2 = s[n] - ans1;
	 	cout << ans1 << " " << ans2 << endl;		
	}
	
	return 0;
}
