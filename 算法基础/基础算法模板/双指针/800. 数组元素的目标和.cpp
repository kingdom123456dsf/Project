#include<cstdio>
#include<iostream>

using namespace std;

const int N = 100010;
int a[N], b[N];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i ++ ) scanf("%d", &b[i]);
	
	bool flag = true;
	for(int i = 1, j = 1; i <= n; i ++ )
	{
		while(j < m && a[i] != b[j]) j ++;
		if(i != n && j == m) flag = false; 
		if(a[i] != b[j]) flag = false;
		//特判,若是下一位相同，不能再用当前位置 
		if(a[i + 1] == b[j]) j ++;
	}
	if(flag) printf("Yes");
	else printf("No");
	
	return 0;
}
