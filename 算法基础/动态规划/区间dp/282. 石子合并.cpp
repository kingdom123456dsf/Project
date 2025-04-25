#include<iostream>
#include<algorithm>

using namespace std;

const int N = 310;
int s[N];//前缀和
int f[N][N];//i到j的最小代价 

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> s[i], s[i] += s[i - 1];
	
	for(int len = 2; len <= n; len ++ )//枚举区间长度
	{
		for(int i = 1; i + len - 1 <= n; i ++ )//区间左端点
		{
			int j = i + len - 1;//区间右端点
			f[i][j] = 1e8;//给一个最大值
			for(int k = i; k <= j - 1; k ++ )
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]); 
			} 
		} 
	} 
	
	cout << f[1][n] << endl;//1到n的最小代价 
	
	return 0;
}
