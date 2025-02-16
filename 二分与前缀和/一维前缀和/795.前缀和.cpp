#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 100010;
int a[N];//原数组
int s[N];//前缀和数组,因为是定义的全局变量的数组,所以s[0]默认为0 
int n,m;

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	
	while(m--)
	{
		int l,r;
		scanf("%d%d", &l, &r);
		printf("%d", s[r] - s[l - 1]);
	}
	
	return 0;
} 
