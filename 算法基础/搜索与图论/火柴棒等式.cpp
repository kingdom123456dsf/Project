#include<iostream>

using namespace std;

//g[0] ~ g[9]记录从0 ~ 10每一个数字需要的火柴数目
int g[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 

int cal(int x)
{
	if(x == 0) return g[0];
	
	int t = 0, ans = 0;
	while(x)
	{
		t = x % 10;
		ans += g[t];
		x /= 10;
	}
	
	return ans;
 } 

int main()
{
	int n;
	cin >> n;
	
	int res = 0;
	for(int i = 0; i <= 1000; i ++ )
	{
		for(int j = 0; j <= 1000; j ++ )
		{
			int sum = i + j;
			if(cal(i) + cal(j) + cal(sum) + 4 == n)
			{
				res ++;
			}
		}
	}
	
	cout << res << endl;	
	
	return 0;
}
