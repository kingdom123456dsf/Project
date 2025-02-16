#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long LL;

const int N = 1000010;

LL s[N],cnt[N];

int main() {
	int n, k;
	scanf("%d%d",&n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &s[i]);
		s[i] += s[i - 1];//前缀和数组
	}



	LL res = 0;
	cnt[0] = 1;
	for(int i = 1; i <= n; i++) {
		res += cnt[s[i] % k];
		++cnt[s[i] % k];
	}

	printf("%lld", res);
	return 0;
}
