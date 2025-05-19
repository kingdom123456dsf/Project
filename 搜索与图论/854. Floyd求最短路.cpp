#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 210, INF = 1e9;
int d[N][N];//�洢��a��b�����·��
int n, m, Q;//n���㣬m���ߣ�Q��ѯ�� 

void floyd()
{
	for(int k = 1; k <= n; k ++ )
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= n; j ++ )
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);	
}

int main()
{
	cin >> n >> m >> Q;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= n; j ++ )
			if(i == j) d[i][j] = 0;//�Ի�Ϊ0	
			else d[i][j] = INF;//������ȳ�ʼ��Ϊ���ֵ
			
	while(m -- )
	{
		int x, y, w;
		cin >> x >> y >> w;
		
		d[x][y] = min(w, d[x][y]);//�ر�ȡ��� 
	}
	
	floyd();//��һ���Ժ�d��ľ�������֮������·�� 
	
	while(Q -- )
	{
		int x, y;
		cin >> x >> y;
		
		if(d[x][y] > INF / 2) puts("impossible");//û�����· 
		else cout << d[x][y] << endl;
	}
	
	return 0;
}
