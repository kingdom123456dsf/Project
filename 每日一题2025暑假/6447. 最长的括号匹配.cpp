#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	stack<int> stk;//存下标 
	
	int res = 0;
	for(int i = 0; i < s.size(); i ++ )
	{
		if(s[i] == ')' && stk.size() && s[stk.top()] == '(')//当前是右括号，且前有与之匹配的左括号 
		{
			stk.pop();
			if(stk.size()) res = max(res, i - stk.top());
			else res = max(res, i + 1);//从开头到i都是 
		}
		else stk.push(i);
	}
	
	cout << res << endl; 
	
	return 0;
}
