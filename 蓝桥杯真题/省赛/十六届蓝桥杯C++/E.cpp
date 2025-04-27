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
	
	//ԭ������ֵ��С�ģ�ƽ����Ҳ��С
	//ѡ������Ǿ����ܴ�С����ѡ�����Ҳ�ֵԽСԽ��
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

