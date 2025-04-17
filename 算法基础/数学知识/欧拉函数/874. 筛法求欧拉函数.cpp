#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int primes[N], cnt;//质因子
bool st[N];
int phi[N];//质因子个数，欧拉函数

void get_eulers(int n)
{
	phi[1] = 1;//1的质因数只有自己 
	for(int i = 2; i <= n; i ++ )//找2 ~ n 的所有 
	{
		if(!st[i])
		{
			primes[cnt ++ ] = i;//当前为质因数
			phi[i] = i - 1;//因为当前为质因数，那么它的质因数个数就是i - 1 
		}
		for(int j = 0; primes[j] <= n / i; j ++ )
		{
			st[primes[j] * i] = true;
			if(i % primes[j] == 0)
			{
				phi[i * primes[j]] = phi[i] * primes[j];
				break;
			} 
			phi[i * primes[j]] = phi[i] * (primes[j] - 1);
		}
	}
}
 

int main()
{
	int n;
	cin >> n;
	
	get_eulers(n);//求1 ~ n每个数的质因子个数
	
 	LL res = 0;
 	for(int i = 1; i <= n; i ++ )
 	{
 		res += phi[i];
	}
	cout << res << endl;
	
	return 0;
}
