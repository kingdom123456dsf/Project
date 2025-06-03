#include<iostream>

using namespace std;

int n, w;
int x;

int main()
{
	cin >> n >> w;
	int t = w;//开始的星期
	int y = 0, c = 0;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> x;
		if(x >= 35)
		{
			if(t != 4) y ++;
			else c ++;
		}
		t ++;
		if(t == 8) t = 1;		
	} 
	
	cout << y << " " << c << endl;
	
	return 0;
}
