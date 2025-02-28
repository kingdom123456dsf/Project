#include<iostream>
#include<algorithm>
#include<cstring>

typedef long long LL;

using namespace std;

const int N = 100010;
int a[N],b[N],c[N];

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0;i < n;i++) scanf("%d", &a[i]);
	for(int i = 0;i < n;i++) scanf("%d", &b[i]);
	for(int i = 0;i < n;i++) scanf("%d", &c[i]);
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n); 
	
	LL res = 0;
	for(int i = 0;i < n;i++)
	{
		int l = 0, r = n - 1;
		while(l < r)
		{
			int mid = l + r + 1 >> 1;
			if(a[mid] < b[i]) l = mid;
			else r = mid - 1;  
		}
		if(a[l] >= b[i])
		{
			l = -1;//错误处理 
		}
		int a = l;
		
		l = 0, r = n - 1;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(c[mid] > b[i]) r = mid;
			else l = mid + 1;
		}
		if(c[r] <= b[i])
		{
			r = n;//错误处理 
		}
		int b = r;
		res += (LL)(a + 1) * (n - b);
	}
	
	printf("%lld\n", res);
	
	return 0;
}
