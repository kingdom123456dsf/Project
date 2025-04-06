#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	
	cout << a / __gcd(a, b) * b << endl;	
	
	return 0;
}
