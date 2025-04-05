#include<iostream>
#include<cstring>

using namespace std;

typedef long long LL;

bool st[200];//因为字符的ASCII码为97(从a开始) 

int main()
{
	string s;
	cin >> s;
	
	LL res = 0;
	for(int i = 0; i < s.size(); i ++ )
	{
		memset(st, false, sizeof st);
		int j = i;
		LL sum = 0;
		while(j < s.size())
		{
			char x = s[j];
			if(!st[x])
			{
				sum ++;
				st[x] = true;
			}
			res += sum;
			j ++;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
