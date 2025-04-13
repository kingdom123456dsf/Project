#include<iostream>

using namespace std;

typedef long long LL;
int t;

int main()
{
	cin >> t;
	while(t -- )
	{
		LL a, b, c, k;
		cin >> a >> b >> c >> k;
		while(k -- )
		{
			LL a1 = (b + c) / 2;
			LL b1 = (a + c) / 2;
			LL c1 = (a + b) / 2;
			a = a1, b = b1, c = c1;
			//!!!!!!!!!!!!
			if(a == b && b == c) break;
		}
		cout << a << " " << b << " " << c << endl;
	}
	
	
	return 0;
}
