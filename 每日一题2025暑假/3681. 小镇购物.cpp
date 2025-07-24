#include<iostream>
#include<set>

using namespace std;

set<string> res;

int main()
{
	int n;
	cin >> n;
	
	while(n -- )
	{
		string s;
		cin >> s;
		res.insert(s);
	}
	
	cout << 52 - res.size() << endl;
	
	return 0;
}
