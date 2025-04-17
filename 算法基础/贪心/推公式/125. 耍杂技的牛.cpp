#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef pair<int, int> PII;

const int N = 500010;
PII q[N];

bool cmp(PII a, PII b)
{
	return a.first + a.second > b.first + b.second;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++ )
	{
		int w, s;
		scanf("%d%d", &w, &s);
		q[i].first = w, q[i].second = s;
	}
	
	sort(q, q + n, cmp);//´óµÄÅÅ
	
	int res = -1e9, sum = 0;
	for(int i = n - 1; i >= 0; i -- )
	{
		int w = q[i].first, s = q[i].second;
		res = max(res, sum - s);
		sum += w;
	} 
	
	printf("%d", res);
	
	return 0;
}
