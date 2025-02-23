#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N = 200010;
LL a[2 * N], s[2 * N];
int t,n,m;

int main(){
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++)
		{
			scanf("%lld", &a[i]);
			a[i] %= m;
			a[i + n] = a[i] + m;
		} 
		sort(a + 1,a + 1 + n + n);//将整个数组排序(后面n个是加上m的数组)
		
		for(int i = 1;i <= 2 * n;i++)
			s[i] = s[i - 1] + a[i];
			
		LL res = 1e18;
		for(int i = 1;i <= n;i++)//***注意是取长度为n的区间 
		{
			int l = i,r = i + n - 1;
			int mid = l + r >> 1;
			LL sum = ((mid - l + 1) * a[mid] - (s[mid - 1] - s[l - 1])) + 
			((s[r] - s[mid]) - (r - mid + 1) * a[mid]);
			res = min(res, sum);
		}
		
		cout << res << endl;
	}
	
	return 0;
}
