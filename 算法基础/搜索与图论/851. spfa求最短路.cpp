#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int n, m;

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int spfa()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	queue<int> q;
	q.push(1);//�������
	st[1] = true;//���������
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		
		st[t] = false;
		//�ҵ�t���Ե���ĵ�(t�����ȥ�ı�) 
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];//����ĵ�
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			} 
		}
	}
	
	return dist[n];
}

int main()
{
	memset(h, -1, sizeof h);//��ӱ��ͷ�����˳�ʼ�� 
	
	cin >> n >> m;
	for(int i = 0; i < m; i ++ )
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	
	int t = spfa();
	if(t == 0x3f3f3f3f) puts("impossible");
	else cout << t << endl;	
	
	return 0;
}
