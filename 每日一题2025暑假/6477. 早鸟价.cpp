#include<iostream>

using namespace std;

int n;
int m, d, c;

void check(int x)
{
	if(c == x) cout << "Ok!" << endl;
	else if(c < x) cout << "Need more!" << endl;
	else cout << "^_^" << endl; 
}

int main()
{
	cin >> n;
	
	while(n -- )
	{
		cin >> m >> d >> c;
		
		if(m == 7 && d > 11 || m > 7) cout << "Too late!" << endl;
		
		else if(m == 6 && d <= 20 || m < 6)
		{
			check(1800);
		}
		
		else if(m == 6 && d > 20 || m > 6)
		{
			check(2000);
		}
	}
	
	return 0;
}
