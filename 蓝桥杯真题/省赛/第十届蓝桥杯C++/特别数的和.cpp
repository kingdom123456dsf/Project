#include<iostream>

using namespace std;

bool is_valid(int x)
{
	int t = 0;
	while(x)
	{
		t = x % 10;
		if(t == 2 || t == 0 || t == 1 || t == 9) return true;
		x /= 10;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	
	int res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		if(is_valid(i)) res += i;
 	}
	
	cout << res << endl;
	
	return 0;
}
