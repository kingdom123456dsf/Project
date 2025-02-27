#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>//取整函数

using namespace std;

const int N = 2e5 + 10;
int h[N], a[N], rk[N];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
		{
			int t;
			scanf("%d", &t);
			rk[t + 1] = i;//第i个数的排名为ti + 1 
		}
		
		int l = 0;//最小值 
		int r = 1e9;//最大值,因为最大值为1e9,最小值为1,从1增长到1e9最多需要1e9 - 1
		for(int i = 1; i < n; i++)
		{
			int A = h[rk[i]] - h[rk[i + 1]];//hr1 - hr2
			int B = a[rk[i + 1]] - a[rk[i]];//ar2 - ar1
			
			if(B > 0) 
				r = min(r, (int)ceil((double)A / B) - 1);//x < ...(可以转换为x <= 上取整 - 1)
			else if(B < 0) 
				l = max(l, (int)floor((double)A / B) + 1);//x > ...(可以转换为x >= 下取整 + 1)
			else if(A <= 0)
			{
				r = -1;//无解 
				break;
			}
		}
		
		if(l > r) l = -1;//因为是取最小的x,所以最后输出l 
		printf("%d\n", l);
	}
	
	return 0;
} 
