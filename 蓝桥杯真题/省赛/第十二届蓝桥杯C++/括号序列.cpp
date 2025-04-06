#include<iostream>
#include<cstring>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
	string s;
	cin >> s;
	
	int n = s.size();
	s = ' ' + s;//让s的坐标从1 ~ n 
	
	bool flag;
	int st = 0;
	cout << "n = " << n << endl;
	for(int i = 1; i <= n; i ++ )
	{
	 	if(s[i] == ')')
		{
			cout << i << endl;
		 	flag = true;
		 	st = i - 1;
			break; 
		} 	
	}
	
	int res = 0;
	if(flag)//代表有右括号
	{
		cout << "YES" << endl;
		if(st + 1 == n)//右括号在最后一位
		{
			//st + (st - 2) * (st - 1)的组合数 
			res = st % MOD + ((st - 2) % MOD) * ((st - 1) % MOD); 
		}
		else//右括号不在最后一位 
		{
			int a = st % MOD + ((st - 2) % MOD) * ((st - 1) % MOD);
			int b = 0;
			for(int i = n - 1; i > st; i -- )
			{
				b += i % MOD;
			}
			b = (b + 1) % MOD;
			res = a * b;
		} 
	}
	else//无右括号 
	{
		cout << "NO" << endl;
		//公式就是求1 ~ (n - 1) + 1的数 
		for(int i = n - 1; i >= 1; i -- )
		{
			res += i % MOD;
		}
		res = (res + 1) % MOD;
	} 
	
	cout << res << endl;	
	
	return 0;
}
