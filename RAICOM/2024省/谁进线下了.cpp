#include<iostream>

using namespace std;

const int N = 25;
int res[N];
int p, k;
int n;

int check(int x)
{
	if(x == 1) return 12;
	if(x == 2) return 9;
	if(x == 3) return 7;
	if(x == 4) return 5;
	if(x == 5) return 4;
	if(x == 6 || x == 7) return 3;
	if(x >= 8 && x <= 10) return 2;
	if(x >= 11 && x <= 15) return 1;
	if(x >= 16 && x <= 20) return 0;
}

int main()
{
	cin >> n;

	while(n -- )
	{
		for(int i = 1; i <= 20; i ++ )
		{
			cin >> p >> k;
			res[i] += check(p);
			res[i] += k;
		}
	}
	
	for(int i = 1; i <= 20; i ++ )
	{
		cout << i << " " << res[i] << endl;
	}	
	
	return 0;
}
