#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int N = 11;

set<int> g[N];//�Զ�ȥ�ر�
int dist[N], d1, d2;//��㣬���͵ڶ��� 

void dfs(int u, int distance)
{
	dist[u] = distance;
	
	for(auto v : g[u])//ö���ڽӵ� 
	{
		//�߻����߹��ĵ㣨���ɻ��� 
		if(dist[v])
		{
			int d = dist[u] - dist[v] + 1;//�ж��м������
			//�޸����͵ڶ���
			if(d > d1) d2 = d1, d1 = d;
			else if(d < d1 && d > d2)  d2 = d; 
		}//���ɻ��˾�ֱ�ӻ��ݼ��� 
		else dfs(v, distance + 1);//�������ö�� 
	}
	
	dist[u] = 0;//�ָ��ֳ� 
}

int main()
{
	int t;
	cin >> t;
	
	while(t -- )
	{
		int n, m;
		cin >> n >> m;
		
		//���G
		for(auto& e: g) e.clear(); 
		
		d1 = 1, d2 = 0;//ֻ��һ����ʱ 
		while(m -- )
		{
			int a, b;
			cin >> a >> b;
			if(a == b) continue;//�Ի�����
			//�������������ϵĵ�����ͨ
			d1 = 2, d2 = 1;
			g[a].insert(b), g[b].insert(a); //�Զ�ȥ�ر�
		}
		
		//ö��ÿһ����Ϊ���
		for(int i = 1; i <= n; i ++ ) dfs(i, 1);//����1��ʼ 
		
		cout << d1 << ' ' << d2 << endl; 
	}	
	
	return 0;
}
