#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
LL a[N], b[N];
int n;

int main()
{
	//贪心思想：都从小到大排序以后，遍历A从小往大放B，
	//放不下去的就是需要替换的 
	
	//Ai < Bi则需要替换 
	//0是正整数吗？ 不是
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
	
	for(int i = 1; i <= n; i ++ ) scanf("%lld", &b[i]);
	
	sort(a + 1, a + 1 + n); 
	
	sort(b + 1, b + 1 + n);
	
	int res = 0;
	for(int i = 1; i <= n; i ++ )//枚举b 
	{
		int j = i;//找a 
		while(j <= n)
		{
			if(a[j] > b[i])//则不需要换 
			{
				i ++;
				res ++;
			}
			j ++;
		}
	}
	cout << n - res << endl;
	
	return 0;
}
