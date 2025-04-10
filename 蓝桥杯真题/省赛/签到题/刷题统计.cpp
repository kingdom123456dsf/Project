#include<iostream>
#include<cstdio>

using namespace std;

typedef long long LL;

int main()
{
	LL a, b, n;
	scanf("%lld%lld%lld", &a, &b, &n);
	
	LL week = a * 5 + b * 2;//一周总刷题数
	
	LL res = 0;
	
	res = (n / week) * 7;//天数 
	n %= week;//剩下一周以内的题量 
	
	LL sum = 0;
	bool flag = false;
	for(int i = 0; i < 5; i ++ )
	{
		if(n == 0)
		{
			flag = true;
			break;
		}
		sum += a;
		res ++;
		if(sum >= n)
		{
			flag = true;
			break;			
		}
	}
	
	if(!flag)
	{
		for(int i = 0; i < 2; i ++ )
		{
			sum += b;
			if(sum >= n) break;
		}
	}
	
	printf("%lld", res);
	
	return 0;
}
