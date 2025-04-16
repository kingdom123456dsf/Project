#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 6010;
int h[N], e[N], ne[N], idx;//�ڽӱ�ͼ,��ͷ,��ǰԪ��ֵ,ָ���� 
int happy[N];//���˶� 
int f[N][2];//״̬��ʾ0/1ѡ��ѡ��ǰ�ڵ�
bool has_fa[N];//�Ƿ��и��ڵ�,�൱���Ҹ��ڵ� 

void add(int a, int b)//��ͼ,��a�����b 
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{
	f[u][1] = happy[u];//��ǰѡ
	
	for(int i = h[u]; i != -1; i = ne[i])//�����ӽڵ� 
	{
		int j = e[i];
		dfs(j);//����
		
		f[u][1] += f[j][0];//���ڵ�ѡ���ӽڵ㲻��ѡ
		f[u][0] += max(f[j][0], f[j][1]); 
	} 
} 

int main()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i ++ ) cin >> happy[i];
	
	memset(h, -1, sizeof h);//����ͷ��ʼ��
 	
 	for(int i = 1; i <= n - 1; i ++ )
 	{
 		int a, b;
 		cin >> a >> b;//������
		add(b, a);//b�Ǹ��ڵ� 
		has_fa[a] = true;//a�и��ڵ��� 
	}
	
	int root = 1;//�ҵ����ڵ�
	while(has_fa[root]) root ++;
	
	dfs(root);//�Ӹ��ڵ㿪ʼ�ݹ�
	
	cout << max(f[root][0], f[root][1]);//���ڵ�ѡ��ѡ 
	
	return 0;
}
