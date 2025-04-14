//#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N = 100010;
LL a[N];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i ++ )
	{
		scanf("%lld", &a[i]);
	}
	
	//原本数差值最小的，平方差也最小
	//选择策略是尽可能从小往大选，并且差值越小越好
	sort(a, a + n);
	
	LL res = 1e12;
	for(int i = 0; i < n; i ++ )
	{
		int j = i + 1;
		LL ans = 0;
		while(j < i + m && j < n)
		{
			ans += a[j] * a[j] - a[j - 1] * a[j - 1];
			j ++;
		}
		res = min(res, ans);
	}
	printf("%lld", res);

	return 0;
}

