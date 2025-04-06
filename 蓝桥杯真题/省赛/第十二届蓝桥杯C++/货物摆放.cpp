#include<iostream>
#include<set>

using namespace std;

typedef long long LL;//2^63 - 1

int main()
{
	//先求出组合数，最后给它乘上3就好(排列)
 	LL target;//2021041820210418
// 	cin >> target;
	target = 2021041820210418;
  
	LL res = 0;
	for(LL i = 1; i * i * i <= target; i ++ )
	{
		if(target % i == 0)//如果当前i是结果数的 
		{
			for(LL j = i; i * j * j <= target; j ++ )
			{
				if(target / i % j == 0)//j也是结果数
				{
					LL k = target / i / j;//减少一层循环的复杂度
					if(i == j && j == k) res ++;//三个数相等就一个排列
					else if(i != j && j != k) res += 6;//A32(全排列，三个数都不等)
					else res += 3;//C31,插空（有两个数相等） 
				} 
			}
		}
	}
	
	cout << res << endl;
	
	return 0;
}
