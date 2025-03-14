#include<iostream>
#include<stack>

using namespace std;

stack<int> mystack;

int main()
{
	int m;
	cin >> m;
	while(m --)
	{
		string s;
		cin >> s;
		int a;
		if(s == "push")
		{
			cin >> a;
			mystack.push(a);
		}
		else if(s == "pop")
		{
			mystack.pop();
		}
		else if(s == "query")
		{
			cout << mystack.top() << endl;
		}
		else if(s == "empty")
		{
			if(mystack.empty()) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	
	
	return 0;
}
