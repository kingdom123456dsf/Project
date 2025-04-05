#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int k;
	cin >> k;
	string s;
	char c1, c2;
	cin >> s >> c1 >> c2;
	
	long long c1num = 0, ans = 0;
	for(int i = 0, j = k - 1; j < s.size(); i ++, j ++ )
	{
		if(s[i] == c1) c1num ++;
		if(s[j] == c2) ans += c1num;
	}
	
	cout << ans << endl;
	
	
	return 0;
}
