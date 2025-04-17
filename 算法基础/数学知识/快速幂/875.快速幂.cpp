#include<iostream>
#include<cstdio>

using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p)
{
	LL res = 1;
	while(b)
	{
		if(b & 1) res = res * a % p;//最后一位若是1，则有2的次幂 
		b >>= 1;//右移一位 
		a = a * (LL)a % p;
	}
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	while(n -- )
	{
		int a, b, p;
		scanf("%d%d%d", &a, &b, &p);
		
		printf("%lld\n", qmi(a, b, p)); 
	}
	
	return 0;
}
