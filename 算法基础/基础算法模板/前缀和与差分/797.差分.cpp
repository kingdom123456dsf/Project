#include<iostream>
#include<cstdio>

using namespace std;

const int N = 100010;
int a[N], s[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++ )
	{
		scanf("%d", &a[i]);
		s[i] = a[i] - a[i - 1];//差分数组 
		//变回原数组：a[i] = s[i] + a[i - 1] 
	}
	
	while(m -- )
	{
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		s[l] += c;
		s[r + 1] -= c;
	}
	
	for(int i = 1; i <= n; i ++ )
	{
		a[i] = s[i] + a[i - 1];
		printf("%d ", a[i]);
	}
	
	return 0;
}
