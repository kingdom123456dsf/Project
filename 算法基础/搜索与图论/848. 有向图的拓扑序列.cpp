#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], idx;
int d[N], ans[N];//d��¼���,qģ����� 
int n, m;

void add(int a, int b)//��ӱ� 
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++ ;
} 

bool topsort()
{
	queue<int> q;
	for(int i = 1; i <= n; i ++ )
	{
		if(!d[i]) q.push(i);//����������� 
 	}
 	
 	int cnt = 0;
 	while(q.size())
 	{
 		auto t = q.front();q.pop();//q��ʵ���������������������� 
 		ans[cnt ++ ] = t;//���t��ʵ������������ 
 		
 		for(int i = h[t]; i != -1; i = ne[i])
 		{
 			int j = e[i];
 			d[j] -- ;
 			if(!d[j]) q.push(j);//�����µ������ 
		}
	}
	
	return cnt == n;//���е㶼���� 
}

int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b] ++ ;//b�����ȶ�1 
	}
	
	if(topsort())
	{
		for(int i = 0; i <= n - 1; i ++ )
		{
			cout << ans[i] << " ";
		}
	}
	else puts("-1");
	
	
	return 0;
}
