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
		if(l[x] == 1) cnt++;//��¼ÿ�����ٳ���һ�ε��� 
	}
	
	LL res = 0;
	for(int i = n;i >= 1;i--)
	{
		LL x = w[i];
		r[x]++, l[x]--;//�ұ߳����ˣ���߼�ȥ�� 
		if(l[x] == 0) cnt--;//�����û����ʱ�������һ 
		if(r[x] == 2)
		{
			 res += cnt;
			 if(l[x] > 0) res--;//������Ҳ��b���𰸼�ȥ1 
		}
	}
	
	printf("%lld", res);
	
	return 0;
}
