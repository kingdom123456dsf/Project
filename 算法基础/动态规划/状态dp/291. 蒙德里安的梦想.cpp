#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 12, M = 1 << N;//数量用二进制表示
long long f[N][M];//表示的是在第i列，并且当前列上有前一行伸出的j个小方格的数量 
bool st[M];//表示的是连续没有伸出小方格的行是偶数个还是奇数个 
int n, m;

int main()
{
 	while(cin >> n >> m, n || m)
 	{
 		//预处理st
		for(int i = 0; i < 1 << n; i ++ )
		{
		 	int cnt = 0;//连续为0的数量
			st[i] = true;//默认是偶数个,因为偶数个才能竖着放2 * 1
			for(int j = 0; j < n; j ++ )
			{
				if(i >> j & 1)
				{
					if(cnt & 1) st[i] = false;//奇数
					cnt = 0; 
				}	 
				else cnt ++;
			}
			if(cnt & 1) st[i] = false;//处理最一行 
		}
		
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for(int i = 1; i <= m; i ++ )
			for(int j = 0; j < 1 << n; j ++ )	
				for(int k = 0; k < 1 << n; k ++ )
					if((j & k) == 0 && st[j | k])
			  			f[i][j] += f[i - 1][k];
						  
		cout << f[m][0] << endl;//第m列并且伸出来小格子为0的结果(因为最多到第m - 1列，必须是刚好放好的)  
	}
	
	
	return 0;
} 
