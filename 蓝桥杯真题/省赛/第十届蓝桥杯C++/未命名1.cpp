#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

typedef pair<int, int> PII;

queue<PII> q;//�洢���� 
int g[60][60];//�洢�Թ� 
bool st[60][60];//��¼ÿһ��λ���Ƿ��߹� 
int pre[60][60];//��¼���ĸ�����������
string path;//��¼���

//�¡����ҡ���; D��L��R��U 
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};

void bfs(int x, int y)
{
	q.push({x, y});
	st[x][y] = true;//��¼Ϊ�߹� 
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		
		for(int i = 0; i < 4; i ++ )
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			
			if(a >= 0 && a < 4 && b >= 0 && b < 6 && g[a][b] == 0 && !st[a][b])
			{
				st[a][b] = true;
				pre[a][b] = i;//���ĸ�����������
				q.push({a, b}); 
			}
		}
	}
	
	int x1 = 3, y1 = 5;//��¼·��
	while(x1 != 0 || y1 != 0)
	{
		int d = pre[x1][y1];
		path += dir[d];
		x1 -= dx[d];
		y1 -= dy[d];
	} 
	reverse(path.begin(), path.end());
}

int main()
{
 	for(int i = 0; i < 4; i ++ )//�� 
 	{
 		for(int j = 0; j < 6; j ++ )//�� 
 		{
 			char c;
 			cin >> c;
 			g[i][j] = c - '0';
		}
	}
	for(int i = 0; i < 4; i ++ )//�� 
 	{
 		for(int j = 0; j < 6; j ++ )//�� 
 		{
 			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	
	bfs(0, 0);
	
	cout << path << endl;

	return 0;
}

