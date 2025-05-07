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
		
		while(stk.size() && stk.top() >= x) stk.pop() ;//若是栈顶大于当前数
		
		if(stk.size()) printf("%d ", stk.top());//若是栈不空，则找到了第一个比当前数小的
		else printf("-1 ");
		
		stk.push(x);
	}
	
	return 0;
}
