#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	stack<int> stk;//���±� 
	
	int res = 0;
	for(int i = 0; i < s.size(); i ++ )
	{
		if(s[i] == ')' && stk.size() && s[stk.top()] == '(')//��ǰ�������ţ���ǰ����֮ƥ��������� 
		{
			stk.pop();
			if(stk.size()) res = max(res, i - stk.top());
			else res = max(res, i + 1);//�ӿ�ͷ��i���� 
		}
		else stk.push(i);
	}
	
	cout << res << endl; 
	
	return 0;
}
