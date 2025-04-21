#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int res = 0;
	while(n -- )
	{
		int x;
		cin >> x;
		res ^= x;
	}
	
	//若是异或结果不是0，那么先手可以把它变为0，也就是先手必胜了 
	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	
	return 0;
}
