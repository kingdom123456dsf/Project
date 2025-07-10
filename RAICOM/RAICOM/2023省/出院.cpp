#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;

map<string, char> mp;
int n, m;

int main()
{
	cin >> n >> m;
	while(n -- )
	{
		string k;
		char v;
		cin >> k >> v;
		mp[k] = v;
	}
	
	while(m -- )
	{
		string s;
		cin >> s;
		
		if(mp.find(s) != mp.end())
		{
			cout << mp[s] << endl;
			continue; 
		}
		
		int cnt = 0;
		int x = 0;
		for(int i = 0; i < s.size(); i ++ )
		{
			if(mp.find(s.substr(0, i)) != mp.end() && mp.find(s.substr(i)) != mp.end())
			{
				cnt ++ ;
				x = i;
			}
		}
		if(!cnt || cnt > 1)
		{
			cout << "D" << endl;
		}
		else cout << mp[s.substr(0, x)] << mp[s.substr(x)] << endl;
	}
	
	
	return 0;
}
