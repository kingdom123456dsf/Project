#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef long long LL;

const int N = 100010;
LL a[N];
int n, m;

bool cmp(LL a, LL b)
{
	return a > b;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n + m + 1; i ++ ) scanf("%lld", &a[i]);
	
	sort(a, a + n + m + 1, cmp);//从大到小排序 
	
	LL res = 0;
	for(int i = 0; i < n + m + 1; i ++ )
	{
		if(i <= n) res += a[i];
		else res -= a[i];
	}
	
	printf("%d", res);
	
	return 0;
}
