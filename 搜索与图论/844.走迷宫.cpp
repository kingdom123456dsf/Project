#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm> 

using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int g[N][N], d[N][N];//g��ʾ��ͼ��d��ʾ��ǰ����Ĳ���
int n, m;
queue<PII> q;

int bfs()
{
	memset(d, -1, sizeof(d));//��ʼ��Ϊ-1��ʾû���߹� 
	
	d[0][0] = 0;//(0, 0)���꿪ʼ��Ҳ�����߹��� 
	q.push({0, 0});//������(0, 0)��ʼ
	
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//��������
 	
 	while(q.size() != 0)//���в�Ϊ�� 
 	{
 		auto t = q.front();//�ó���ͷ 
 		q.pop();//���� 
 		
 		for(int i = 0; i < 4; i ++ )//ö���ƶ����� 
 		{
 			int x = t.first + dx[i], y = t.second + dy[i];
 			
 			if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
 			{
 				d[x][y] = d[t.first][t.second] + 1;//��һ���һ
				q.push({x, y});//��ǰ���������� 
			}
		}
	}
	
	return d[n - 1][m - 1];//����(n, m)//���괦 
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i ++ )
		for(int j = 0; j < m; j ++ )
			cin >> g[i][j];
			
			
	cout << bfs() << endl;
 	
	return 0;
}
