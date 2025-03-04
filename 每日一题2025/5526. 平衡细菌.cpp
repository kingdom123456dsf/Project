#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long LL;

const int N = 200010;
LL a[N], b[N], c[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	
	for(int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
	for(int i = 1; i <= n; i++) c[i] = b[i] - b[i - 1];
	
	LL res = 0;
	for(int i = 1; i <= n; i++) res += abs(c[i]);
	printf("%lld", res);
	
	return 0;
}
