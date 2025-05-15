#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>

using namespace std;

int bfs(string start)
{
	queue<string> q;
	unordered_map<string, int> d;//表示距离 
	
	q.push(start);
	d[start] = 0;//起点 
	string end = "12345678x";//表示目标状态
	
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		
		int distance = d[t];//距离 
		if(t == end) return distance;
		
		int k = t.find('x');
		int x = k / 3, y = k % 3;//将一维转换为 3 * 3的二维数组 
		
		for(int i = 0; i < 4; i ++ )
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				swap(t[k], t[a * 3 + b]);//状态转移 
				
				if(!d.count(t))//没有走过 
				{
					d[t] = distance + 1;//步数 
					q.push(t);
				}
				
				swap(t[k], t[a * 3 + b]);//恢复状态 
			}
		}
	}
	
	return -1; 
}

int main()
{
	string start;
	for(int i = 0; i < 9; i ++ )
	{
		char c;
		cin >> c;
		start += c;
	}
	
	cout << bfs(start) << endl;
	
	return 0;
}
