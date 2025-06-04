#include<iostream>
#include<cstring>
#include<map>

using namespace std;

int n, m;
map<string, char> mp;

int main()
{
	cin >> n >> m;
	string name;
	char value;
	while(n -- )
	{
		cin >> name >> value;
		mp[name] = value;
	}
	
	string s;
	while(m -- )
	{
		cin >> s;
		if (mp.find(s) != mp.end())//找一模一样的 
        {
            cout << mp[s] << endl;
        }
        else//拼接的 
        {
            int x = 0;//记录第几个位置开始分割 
            int cnt = 0;//判断重复 
            for (int i = 0; i < s.size(); i++)
            {
            	//是拼接的 
                if (mp.find(s.substr(0, i + 1)) != mp.end() && mp.find(s.substr(i + 1)) != mp.end())
                {
                    cnt ++ ;
                    x = i;
                }
            }
            if (!cnt || cnt > 1)//若不是拼接或有重复 
                cout << "D" << endl;
            else//符合所有条件 
            {
                cout << mp[s.substr(0, x + 1)] << mp[s.substr(x + 1)] << endl;
            }
        }
    }
	
	return 0;
}
