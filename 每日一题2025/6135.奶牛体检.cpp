#include<iostream>

using namespace std;

const int N = 7510;
int a[N], b[N], ans[N];
int n,cnt;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	for(int i = 1;i <= n;i++) cin >> b[i];
	
	for(int i = 1;i <= n;i++)//判断初始情况有几头牛对应
		if(a[i] == b[i])  cnt++;
		
	for(int i = 1;i <= n;i++)
	{
		int l = i,r = i;//当奇数头牛时，中间就一个数
		int sum = cnt; 
		while(l >= 1 && r <= n)
		{
			if(l < r)
			{
   			 	if(a[l] == b[l]) sum--;
				if(a[r] == b[r]) sum--;
				if(a[l] == b[r]) sum++;
				if(a[r] == b[l]) sum++;
			}
			ans[sum]++;
			l--,r++;
		}
		
		l = i,r = i + 1;//当偶数头牛时，中间两个数
		sum = cnt; 
		while(l >= 1 && r <= n)
		{
			if(l < r)
			{
   			 	if(a[l] == b[l]) sum--;
				if(a[r] == b[r]) sum--;
				if(a[l] == b[r]) sum++;
				if(a[r] == b[l]) sum++;
			}
			ans[sum]++;
			l--,r++;
		}
	}
		
	
	for(int i = 0;i <= n;i++) cout << ans[i] << endl;
	
	return 0;
}
