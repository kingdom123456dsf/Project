#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

bool is_valid(int x)
{
	if(x < 2) return false;
	for(int i = 2; i <= x / i; i ++ ) 
	{
		if(x % i == 0) return false;
	}
	return true;
}

int main()
{
	int cnt = 0;//Ä¬ÈÏ°üº¬2 
	for(int i = 2; i < 20000; i ++ )
	{
		if(is_valid(i))
		{
			cnt ++;
		}
		if(cnt == 2025)
		{
			cout << i << endl;
			break;
		}
	}
	cout << cnt ;	
//	cout << 17609; 
	
	return 0;
}
