#include<iostream>
#include<cstdio>

using namespace std;

const int N = 100010;
int p[N], num[N];
int n, m;

int find(int x)
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; i ++ )//��ʼ����������ֻ���Լ� 
	{
		p[i] = i;
		num[i] = 1;
	}
	
	while(m -- )
	{
		char op[3];
		int a, b;
		scanf("%s", op);
		if(op[0] == 'C')
		{
			scanf("%d%d", &a, &b);
			if(find(a) == find(b)) continue;
			num[find(b)] += num[find(a)];//�����ͳ�Ƶ��� 
			p[find(a)] = find(b);
		}
		else if(op[1] == '1')
		{
			scanf("%d%d", &a, &b);
			if(find(a) == find(b)) puts("Yes");
			else puts("No");
		}
		else
		{
			scanf("%d", &a);
			printf("%d\n", num[find(a)]);
		}
	}
	
	return 0;
}
