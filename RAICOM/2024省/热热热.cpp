#include<iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	int r1 = 0, r2 = 0;
	while(n -- )
	{
		int x;
		cin >> x;
		if(x >= 35)
		{
			if(m != 4) r1 ++ ;
			else r2 ++ ;
		}
		
		if(m != 7) m ++ ;
		else m = 1;
	}
	
	cout << r1 << " " << r2 << endl; 
	
	return 0;
}
