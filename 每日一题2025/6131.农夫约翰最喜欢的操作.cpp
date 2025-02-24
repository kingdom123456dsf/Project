#include<iostream>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 400010;//因为要开2n
int w[N];
LL s[N];
int n,m; 

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d", &w[i]);
			w[i] %= m;//求余数 
		}
		sort(w + 1, w + n + 1);
		for(int i = 1;i <= n;i++) w[i + n] = w[i] + m;
		
		for(int i = 1;i <= 2 * n;i++) s[i] = s[i - 1] + w[i];//求前缀和数组
		
		LL ans = 1e18; 
		for(int l = 1;l <= n;l++)
		{
			int r = l + n - 1;
			int mid = l + r >> 1;//求中位数
			LL sum = (mid - l + 1) * (LL)w[mid] - (s[mid] - s[l - 1]) +
			(s[r] - s[mid]) - (r - mid) * (LL)w[mid];//从mid + 1开始,因为mid到它自己的距离就是0
			//防止爆int，强转为longlong 
			ans = min(ans, sum);
		}
		
		printf("%lld\n", ans);
	}
	

	return 0;
}
