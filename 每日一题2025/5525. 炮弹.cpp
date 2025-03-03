#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010;
int q[N], v[N];
bool st[N];
int n, x;

int main()
{
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> q[i] >> v[i];
	
	int res = 0;
	int cnt = 0;//存储执行步数
	int e = 1, d = 1;//初始能量和行走方向
	while(cnt < 13 * 2 * N)//给定步数上限防止死循环 
	{
		if(q[x])//如果是炮击目标 
		{
			if(e >= v[x] && !st[x]) 
			{
				st[x] = true;
				res++;
			}
		}
		else e += v[x], d = -d;
		x += e * d;
		cnt++;
		if(x < 1 || x > n) break;
	} 
	
	cout << res << endl;
	
	return 0;
}
