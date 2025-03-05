#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		if(s.back() == '0') cout << 'E' << endl;
		else cout << 'B' << endl;
	}
	return 0;
}
