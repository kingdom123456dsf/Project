#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

typedef long long LL;

const int N = 200010;
LL a[N];//奶牛会长高,int可能会爆 
int b[N];
int n,m;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	
	for(int j = 1;j <= m;j++) scanf("%d", &b[j]);
	
	for(int i = 1;i <= m;i++)
	{
		int t = 0;//记录糖果底部高度
		for(int j = 1;j <= n;j++)
	 	{
	 		if(t >= a[j]) continue;
	 		int ans = min(a[j],(LL)b[i]) - t;
	 		a[j] += ans;
	 		t += ans;
	 		if(t == b[i]) break;//优化，当前糖果若是吃完，直接到下一颗糖果即可 
		}
	} 
	
	for(int i = 1;i <= n;i++)
	{
		printf("%lld\n", a[i]);
	}
	
	return 0;
}
