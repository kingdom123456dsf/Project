#include<iostream>

using namespace std;

int a[20];

int check(int p)
{
	if(p == 1) return 12;
	else if(p == 2) return 9;
	else if(p == 3) return 7;
	else if(p == 4) return 5;
	else if(p == 5) return 4;
	else if(p == 6 || p == 7) return 3;
	else if(p >= 8 && p <= 10) return 2;
	else if(p >= 11 && p <= 15) return 1;
	else return 0;
}

int main()
{
	int n;
	cin >> n;
	
	while(n -- )
	{
		for(int i = 0; i < 20; i ++ )
		{
			int p = 0, k = 0;
			cin >> p >> k;
			int sum = check(p) + k;
			a[i] += sum;
		}
	}
	
	for(int i = 0; i < 20; i ++ )
	{
		cout << i + 1 <<" " << a[i] << endl;
	}
	
	return 0;
}
