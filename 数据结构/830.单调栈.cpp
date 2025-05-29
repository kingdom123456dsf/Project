#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

const int N = 100010;

int n;
stack<int> stk;

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++ )
	{
		int x;
		scanf("%d", &x);
		
		while(stk.size() && stk.top() >= x) stk.pop() ;//����ջ�����ڵ�ǰ��
		
		if(stk.size()) printf("%d ", stk.top());//����ջ���գ����ҵ��˵�һ���ȵ�ǰ��С��
		else printf("-1 ");
		
		stk.push(x);
	}
	
	return 0;
}
