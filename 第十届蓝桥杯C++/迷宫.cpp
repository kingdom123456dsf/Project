#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef pair<int, int> PII;

const int N = 60;
int g[N][N]; 
queue<PII> q;//��������
bool st[N][N];//����ÿ��λ���Ƿ��߹� 
string path;//��¼·�� 
int pre[N][N];//����һ�������¼���ĸ����������� 

//�¡����ҡ��� DLRU 
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};

void bfs(int x, int y)
{
	st[0][0] = true;
	q.push({0, 0});
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		
		for(int i = 0; i < 4; i ++ )
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			if(a >= 0 && a < 30 && b >= 0 && b < 50 && !st[a][b] && g[a][b] == 0)
			{
				st[a][b] = true;
				pre[a][b] = i;//��¼���ĸ����������� 
				q.push({a, b});
			}
		}
	}
	
	//����·��
	int a = 29, b = 49;
	while(a != 0 || b != 0)
	{
		int d = pre[a][b];
		path += dir[d];
		a -= dx[d];
		b -= dy[d];
	}
	reverse(path.begin(), path.end());//��Ϊ�ǴӺ���ǰ��� 	
}

int main()
{
	for(int i = 0; i < 30; i ++ )
	{
		for(int j = 0; j < 50; j ++ )
		{
			char c; 
			cin >> c;
			g[i][j] = c - '0';
		}
	}
	puts("");
	
	bfs(0, 0);
	
	cout << path << endl; 
	
	return 0;
}
