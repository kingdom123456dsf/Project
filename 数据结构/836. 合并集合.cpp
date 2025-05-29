#include<iostream>
#include<cstdio>

using namespace std;

const int N = 100010;
int p[N];//���ڴ洢���ڵ�
int n, m; 

int find(int x)//�ҵ����ڽڵ�+·���Ż� 
{
	if(p[x] != x) p[x] = find(p[x]);//��ÿһ��������ն�ָ������ 
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	
	//��ʼ�������ÿ������ֻ��һ���������ڵ���Ȼ�����Լ� 
	for(int i = 1; i <= n; i ++ ) p[i] = i;
	
	while(m -- )
	{
		char op[2];
		int a, b;
		scanf("%s%d%d", op, &a, &b);
		
		if(*op == 'M') p[find(a)] = find(b);//��a�����嵽b������
		else
		{
			if(find(a) == find(b)) puts("Yes");
			else puts("No");
		} 
	}	
	
	return 0;
}
