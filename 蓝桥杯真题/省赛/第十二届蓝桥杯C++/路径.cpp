#include<iostream>

using namespace std;

int f[2025];

int gcd(int a, int b)//欧几里得算法 
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	for(int i = 1; i <= 2021; i ++ )
	{
		for(int j = i + 1; j <= i + 21; j ++ )//枚举所有可以走的路线 
		{
			if(j > 2021) break;//走出了
			
			if(f[j] == 0)//当前没走过 
				f[j] = f[i] + j / gcd(i, j) * i;//最小公倍数
			else//走过 
		 		f[j] = min(f[j], f[i] + j / gcd(i, j) * i);//最短长度  
		}
	}
	
	cout << f[2021] << endl;//最后的结果就是最短路	
	
	return 0;
}
