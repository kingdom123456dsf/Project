#include<iostream>
#include<cstdio>

using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p)
{
	LL res = 1;
	while(b)
	{
		if(b & 1) res = res * a % p;
		b >>= 1;
		a = a * (LL) a % p;
	}
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	while(n -- )
	{
		int a, p;
		scanf("%d%d", &a, &p);
	
		//a与p互质才可以 
		if(a % p) printf("%lld\n", qmi(a, p - 2, p));//就是求a ^ (p - 2) % p 
		else printf("impossible\n");
	}
	
	return 0;
}
