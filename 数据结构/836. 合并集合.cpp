#include<iostream>
#include<cstdio>

using namespace std;

const int N = 100010;
int p[N];//用于存储父节点
int n, m; 

int find(int x)//找到祖宗节点+路径优化 
{
	if(p[x] != x) p[x] = find(p[x]);//让每一个结点最终都指向树根 
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	
	//初始化，最初每个集合只有一个数，父节点自然就是自己 
	for(int i = 1; i <= n; i ++ ) p[i] = i;
	
	while(m -- )
	{
		char op[2];
		int a, b;
		scanf("%s%d%d", op, &a, &b);
		
		if(*op == 'M') p[find(a)] = find(b);//将a子树插到b树根下
		else
		{
			if(find(a) == find(b)) puts("Yes");
			else puts("No");
		} 
	}	
	
	return 0;
}
