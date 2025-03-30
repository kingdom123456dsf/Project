#include<iostream>
#include<algorithm>

using namespace std;

const int N = 18;
typedef long long LL;
LL q[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++ ) cin >> q[i];
	
	int res = 0;
	for(int i = 1; i < 1 << m; i ++ )//枚举每一个质数选和不选两种情况(二进制表示)
	{
		int t = 1;//当前质数的乘积(用n/t下取整就是当前的倍数的个数)
		int s = 0;//选中的集合数量 
		
		for(int j = 0; j < m; j ++ )//枚举出每一位的情况
		{
			if(i >> j & 1)//若当前位选 
			{
				if((LL)t * q[j] > n)//超出范围了 
				{
					t = - 1;
					break;
				}
				else
				{
					t *= q[j];
					s ++;//当前选中的集合数量 
				}
			}
		} 
		
		if(t == -1) continue;//表示当前情况不符
			
		if(s & 1) res += n / t;//奇数位
		else res -= n / t;//偶数位 
	} 
	
	cout << res << endl;	
	
	return 0;
}
