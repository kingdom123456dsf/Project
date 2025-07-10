#include<iostream>

using namespace std;

typedef long long LL;

int T;

int main()
{
	cin >> T;
	
	while(T -- )
	{
	 	int x1, x2, x3, y1, y2, y3;
		cin >> x1 >> x2 >> x3;
		cin >> y1 >> y2 >> y3;
		
		int res1 = x1 + x2 + x3;
		int res2 = y1 + y2 + y3;
		
		int t = max(max(y1 - x1, y2 - x2), y3 - x3);
		cout << t << endl;
		
		if(res1 != res2) cout << -1 << endl;
		else cout << t / 40 + (t % 40) / 20 << endl;
	}	
	
	return 0;
}
