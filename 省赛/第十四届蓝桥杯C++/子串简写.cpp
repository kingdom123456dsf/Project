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
	
	int res = 0;
	for(int i = 0; i < s.size(); i ++ )
	{
		if(s[i] == c1)
		{
			int j = i + k - 1;
			while(j < s.size())
			{
				if(s[j] == c2) res ++;
				j ++;
			} 
		}
	}
	
	cout << res << endl;
	
	
	return 0;
}
