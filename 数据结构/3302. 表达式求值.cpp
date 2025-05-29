#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>//哈希表

using namespace std;

stack<int> num;//存储数字 
stack<char> op;//存储运算符

//运算符优先级 
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval()
{
	//ba顺序不能返,因为可能会有a - b的运算，顺序反了结果就变了 
	auto b = num.top(); num.pop();//第一个操作数 
	auto a = num.top(); num.pop();//第二个操作数 
	auto c = op.top(); op.pop();//运算符 
	
	int x = 0;//结果 
	//计算结果 
	if(c == '+') x = a + b;
	else if(c == '-') x = a - b;
	else if(c == '*') x = a * b;
	else x = a / b;
	num.push(x);//结果入栈 
}

int main()
{
	string str;
	cin >> str;
	
	for(int i = 0; i < str.size(); i ++)
	{
		auto c = str[i];
		if(isdigit(c))//是数字 
		{
			int x = 0, j = i;
			while(j < str.size() && isdigit(str[j])) x = x * 10 + str[j ++] - '0';//将字符转化为整数
			i = j - 1;//更新
			num.push(x); 
		}
		else if(c == '(') op.push(c);//左括号无优先级，直接入栈 
		else if(c == ')')//从右往左算 
		{
			while(op.top() != '(') eval();
			op.pop(); //到(就弹出 
		}
		else
		{
			while(op.size() && pr[op.top()] >= pr[c])//待入栈的操作符优先级比栈内底 
				eval();//则先运算 
			op.push(c);//操作符入栈 
		}
	}
	
	while(op.size()) eval();//计算剩余运算 
	cout << num.top() << endl;
	
	return 0;
}
