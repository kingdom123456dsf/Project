#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef unsigned long long ULL;//2 ^ 64
//若是溢出就相当于对2 ^ 64取模了,不容易冲突2 ^ 64 

const int N = 100010, P = 131;//P进制值,默认131不容出现冲突 
ULL h[N], p[N];
char str[N];
int n, m;

ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", str + 1);//下标从1开始
	//从0开始的话相当于进位值第0位，不管谁映射，值都是一样的
	
	p[0] = 1;
	for(int i = 1; i <= n; i ++ )//预处理 
	{
		p[i] = p[i - 1] * P;//处理进位制前缀和
		h[i] = h[i - 1] * P + str[i];//P进制的数 ，再加上最低位 
	} 
	
	while(m -- )
	{
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		
		if(get(l1, r1) == get(l2, r2)) puts("Yes");
		else puts("No");
	}	
	
	return 0;
}
