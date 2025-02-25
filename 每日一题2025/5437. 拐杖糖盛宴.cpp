#include<iostream>
#include<algorithm>
#include<cstring>

typedef long long LL;

using namespace std;

const int N = 200010;
LL a[N],b[N];
LL n, m;

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++) cin >> b[i];
	
	for(int i = 1;i <= m;i++)
	{
		LL t = 0;//t代表当前糖的下限 
		for(int j = 1;j <= n;j++)
		{
			if(t >= b[i]) break; //如果已经吃完了糖果，则结束当前循环 
			if(a[j] > t)//若当前牛能吃到糖果 
			{
				LL d = a[j];
				a[j] += min(a[j] - t, b[i] - t);
				t = d;
			}
		}
	}
		
	for(int i = 1;i <= n;i++) cout << a[i] << endl;
	
	return 0;
}
