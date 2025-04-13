#include<iostream>

using namespace std;

int check(int x)
{
	int sum = 0;
	while(x)
	{
		sum += x & 1;
		x >>= 1;
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i ++ )
	{
		int x;
		cin >> x;
		cout << check(x) << " ";
	}
	
	
	return 0;
}
