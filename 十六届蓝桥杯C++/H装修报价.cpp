#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
LL a[N], pre[N], p[N], MOD = 1e9 + 7;
//pre代表前i个数异或的结果,p代表3^i次幂

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	
	p[0] = 1;//3的0次幂等于1 
	for(int i = 1; i <= n; i ++ )//前缀和思想 
	{
		pre[i] = pre[i - 1] ^ a[i] % MOD;//存储前i个数异或的结果 
		p[i] = p[i - 1] % MOD * 3 % MOD;//计算3的i次幂 
	}
	
	LL ans = pre[n];//全部都是异或的情况 
	for(int i = 1; i <= n - 1; i ++ )//只有n - 1个位置放操作符 
	{
		ans = ans % MOD + pre[i] * (2 * p[n - 1 - i) % MOD;
	}
	cout << (ans % MOD + MOD) % MOD << endl;//为了防止答案是负数 
	
	return 0;	
} 
