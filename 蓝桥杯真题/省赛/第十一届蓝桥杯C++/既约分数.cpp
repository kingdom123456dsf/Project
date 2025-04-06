#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{	
	int res = 0;
	//分子分母的位置可以交换，故先枚举出一种情况，最后手动乘上2倍即可
	for(int i = 1; i <= 2020; i ++ )
	{
		int j = i;
		while(j <= 2020)
		{
			if(__gcd(i, j) == 1)
			{
				res ++;
			}
			j ++;
		}
	} 
	
	//因为1/1的情况会记两次，故结果剪一次 
	cout << res * 2 - 1 << endl;	
	
	return 0;
}
