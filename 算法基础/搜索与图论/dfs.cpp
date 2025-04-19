#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(string start)
{
	queue<string> q;
	q.push(start);
	
	unordered_map<string, int> d;
	d[start] = 0;//Æðµã
	
	string end = "12345678x";
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int distance = d[t];
		if(t == end) return distance;
		
		int whe = t.find('x');
		int x = whe / 3, y = whe % 3;
		for(int i = 0; i < 4; i ++ )
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				swap(t[whe], t[a * 3 + b]);
				
				if(!d.count(t))
				{
					d[t] = distance + 1;
					q.push(t);
				}
				
				swap(t[whe], t[a * 3 + b]);
			}
		}
	} 
	
	return -1;
}

int main()
{
	string start;
	for(int i = 0; i < 3; i ++ )
	{
		for(int j = 0; j < 3; j ++ )
		{
			char c;
			cin >> c;
			start += c;
		}
	}
	
	cout << bfs(start);	
	
	return 0;
}
