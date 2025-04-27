#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

stack<char> st;

int main()
{
	string s;
	cin >> s;
	
	
	if(s[0] == ')' || s[s.size() - 1] == '(') 
	{
		cout << 1 << endl;
		return 0;
	}
	
	int a = 0, b = 0;
	for(int i = 0; i < s.size(); i ++ )
	{
		if(s[i] == '(') a ++;
		else b ++ ;
	}
	
	int res = 0;
	if(a - b == 0)
	{
		cout << 0 << endl;
        return 0;
	}
	else if(a > b)//×óÀ¨ºÅ±ÈÓÒÀ¨ºÅ¶à
	{
		for(int i = s.size() - 1; i >= 0; i -- )
		{
			if(s[i] == ')') st.push(s[i]);
			else
			{
				if(st.size() >= 0) res ++;
				if(st.size()) st.pop();
				else break;
 			}
		}
	}
	else if(a < b)//ÓÒÀ¨ºÅ±È×óÀ¨ºÅ¶à
	{
		for(int i = 0; i < s.size() - 1; i ++ )
		{
			if(s[i] == '(') st.push(s[i]);
			else
			{
				if(st.size() >= 0) res ++;
				if(st.size()) st.pop();
				else break;
 			}
		}
	} 
	cout << res << endl;
	
	return 0;
}
