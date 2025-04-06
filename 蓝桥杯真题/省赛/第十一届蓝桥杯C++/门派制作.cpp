#include<iostream>

using namespace std;

int cnt[15];//0 ~ 9

int main()
{
	for(int i = 1; i <= 2020; i ++ )
	{
		int x = i;
		int t = 0;
		while(x)
		{
			t = x % 10;//得到个位数
			cnt[t] ++;
			x /= 10; 
		}
	}
	
	cout << cnt[2] << endl;	
	
	return 0;
}
