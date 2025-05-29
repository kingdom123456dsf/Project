#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>//��ϣ��

using namespace std;

stack<int> num;//�洢���� 
stack<char> op;//�洢�����

//��������ȼ� 
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval()
{
	//ba˳���ܷ�,��Ϊ���ܻ���a - b�����㣬˳���˽���ͱ��� 
	auto b = num.top(); num.pop();//��һ�������� 
	auto a = num.top(); num.pop();//�ڶ��������� 
	auto c = op.top(); op.pop();//����� 
	
	int x = 0;//��� 
	//������ 
	if(c == '+') x = a + b;
	else if(c == '-') x = a - b;
	else if(c == '*') x = a * b;
	else x = a / b;
	num.push(x);//�����ջ 
}

int main()
{
	string str;
	cin >> str;
	
	for(int i = 0; i < str.size(); i ++)
	{
		auto c = str[i];
		if(isdigit(c))//������ 
		{
			int x = 0, j = i;
			while(j < str.size() && isdigit(str[j])) x = x * 10 + str[j ++] - '0';//���ַ�ת��Ϊ����
			i = j - 1;//����
			num.push(x); 
		}
		else if(c == '(') op.push(c);//�����������ȼ���ֱ����ջ 
		else if(c == ')')//���������� 
		{
			while(op.top() != '(') eval();
			op.pop(); //��(�͵��� 
		}
		else
		{
			while(op.size() && pr[op.top()] >= pr[c])//����ջ�Ĳ��������ȼ���ջ�ڵ� 
				eval();//�������� 
			op.push(c);//��������ջ 
		}
	}
	
	while(op.size()) eval();//����ʣ������ 
	cout << num.top() << endl;
	
	return 0;
}
