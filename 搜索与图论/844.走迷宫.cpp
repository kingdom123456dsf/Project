#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm> 

using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int g[N][N], d[N][N];//g表示地图，d表示当前坐标的层数
int n, m;
queue<PII> q;

int bfs()
{
	memset(d, -1, sizeof(d));//初始化为-1表示没有走过 
	
	d[0][0] = 0;//(0, 0)坐标开始，也就是走过了 
	q.push({0, 0});//从坐标(0, 0)开始
	
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//上右下左
 	
 	while(q.size() != 0)//队列不为空 
 	{
 		auto t = q.front();//拿出队头 
 		q.pop();//弹出 
 		
 		for(int i = 0; i < 4; i ++ )//枚举移动方向 
 		{
 			int x = t.first + dx[i], y = t.second + dy[i];
 			
 			if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
 			{
 				d[x][y] = d[t.first][t.second] + 1;//上一层加一
				q.push({x, y});//当前坐标加入队列 
			}
		}
	}
	
	return d[n - 1][m - 1];//返回(n, m)//坐标处 
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
