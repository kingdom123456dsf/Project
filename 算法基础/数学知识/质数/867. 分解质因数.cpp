#include<iostream>

using namespace std;

void divide(int x)
{
	for(int i = 2; i <= x / i; i ++ )
	{
		if(x % i == 0)//从2开始最先枚举到的一定是最小质因数 
		{
			int s = 0;
			while(x % i == 0) x /= i, s ++;
			cout << i << " " << s << endl;
		}
	}
	if(x > 1) cout << x << " " << 1 << endl;//剩下的若大于1，则一定是剩下的一个另一个质因数 
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	
	while(n -- )
	{
		int x;
		cin >> x;
		
		divide(x);//分解质因数 
	}	
	
	return 0;
}
