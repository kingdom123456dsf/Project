#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
	for(int i = 2; i <= n; i ++ )
	{
		if(!st[i])//当前数没被删(是质数)
		{
			primes[cnt ++ ] = i; 
		}
		for(int j = 0; primes[j] <= n / i; j ++ )//小到大枚举质因子 
		{
			st[primes[j] * i] = true;//筛掉合数
			if(i % primes[j] == 0) break; 
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	get_primes(n);
	
	cout << cnt << endl;	
	
	return 0;
}
