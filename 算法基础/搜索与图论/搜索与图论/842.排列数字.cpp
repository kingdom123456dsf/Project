#include<iostream>
#include<cstdio>

using namespace std;

const int N = 10;
int path[N];
bool st[N];
int n;

void dfs(int u)
{
	if(u == n)//�ߵ���ײ� 
	{
		for(int i = 0; i < n; i ++ )//��Ϊu�Ǵ�0��ʼ��
		{
			printf("%d ", path[i]);
		}
		puts("");//���� 
		return;
	}
	
	//��������²���
	for(int i = 1; i <= n; i ++ )//��Ϊ���Ǵ�1��n
	{
		if(!st[i])//û�ù� 
		{
			path[u] = i;
			st[i] = true;
			
			dfs(u + 1);
			//ÿһ�ε���֮������˻ָ��ֳ�
			st[i] = false; 
		}
	} 
}

int main()
{
	cin >> n;
	
	dfs(0);	
	
	return 0;
}
