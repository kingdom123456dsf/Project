#include<iostream>
#include<cstdio>

using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
LL w[N],l[N],r[N];
int n, cnt;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld", &w[i]);
		LL x = w[i];
		l[x]++;
		if(l[x] == 1) cnt++;//记录每个至少出现一次的数 
	}
	
	LL res = 0;
	for(int i = n;i >= 1;i--)
	{
		LL x = w[i];
		r[x]++, l[x]--;//右边出现了，左边减去它 
		if(l[x] == 0) cnt--;//当左边没有它时，结果减一 
		if(r[x] == 2)
		{
			 res += cnt;
			 if(l[x] > 0) res--;//如果左边也有b，答案减去1 
		}
	}
	
	printf("%lld", res);
	
	return 0;
}
