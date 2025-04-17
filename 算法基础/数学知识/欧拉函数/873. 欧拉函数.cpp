#include<iostream>

using namespace std;

typedef long long LL;

LL phi(int x)
{
	LL res = x;
	for(int i = 2; i <= x / i; i ++ )
	{
		if(x % i == 0)
		{
			res = res * (i - 1) / i;//乘上1 - 1/当前质因数 
			while(x % i == 0) x /= i;//将当前质因数除尽 
		}
	}
	if(x > 1) res = res * (x - 1) / x;
	
	return res;
}

int main()
{
	int n;
	cin >> n;
	
	while(n -- )
	{
		int a;
	 	cin >> a;
	 	cout << phi(a) << endl;//欧拉函数 
	}	
	
	return 0;
}
