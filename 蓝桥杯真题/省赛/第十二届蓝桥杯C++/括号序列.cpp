#include<iostream>
#include<cstring>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
	string s;
	cin >> s;
	
	int n = s.size();
	s = ' ' + s;//��s�������1 ~ n 
	
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
	if(flag)//������������
	{
		cout << "YES" << endl;
		if(st + 1 == n)//�����������һλ
		{
			//st + (st - 2) * (st - 1)������� 
			res = st % MOD + ((st - 2) % MOD) * ((st - 1) % MOD); 
		}
		else//�����Ų������һλ 
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
	else//�������� 
	{
		cout << "NO" << endl;
		//��ʽ������1 ~ (n - 1) + 1���� 
		for(int i = n - 1; i >= 1; i -- )
		{
			res += i % MOD;
		}
		res = (res + 1) % MOD;
	} 
	
	cout << res << endl;	
	
	return 0;
}
