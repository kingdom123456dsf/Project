#include<iostream>
#include<cstdio>

using namespace std;

typedef long long LL;
const int N = 200010;
LL a[N];
LL m;
int ans,res;

int main(){
	int t,n;
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d%lld", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
		
		res = 1e9;
		for(int x = 0;x <= m;x++)
		{
			for(int i = 1;i <= n;i++)
			{
			 	a[i] -= x;
			 	int num = a[i] % m; 
			 	if(num > (m / 2)) ans = ans + m - num;
		 		else ans += num;
			}
			res = min(res, ans);
			ans = 0;
		}
		cout << res << endl;
	}
	
	return 0;
}
