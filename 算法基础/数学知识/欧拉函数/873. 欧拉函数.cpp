#include<iostream>

using namespace std;

typedef long long LL;

LL phi(int x)
{
	LL res = x;
	for(int i = 2; i <= x / i; i ++ )
	{
		if(x % i == 0)
		{
			res = res * (i - 1) / i;//����1 - 1/��ǰ������ 
			while(x % i == 0) x /= i;//����ǰ���������� 
		}
	}
	if(x > 1) res = res * (x - 1) / x;
	
	return res;
}

int main()
{
	int n;
	cin >> n;
	
	while(n -- )
	{
		int a;
	 	cin >> a;
	 	cout << phi(a) << endl;//ŷ������ 
	}	
	
	return 0;
}
