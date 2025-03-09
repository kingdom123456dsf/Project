#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10010;
int a[N][N];
int dx[3] = {0, 1, 0}, dy[3] = {1, 0, -1};//ÓÒ£¬ÏÂ£¬×ó
int w, m, n;

int main()
{
	cin >> w >> m >> n;
	int x, y = 0;
	int cnt = 0;
	for(int i = 1; i <= 10000; i++)
	{
		a[x][y] = i;
		int a = x + dx[cnt], b = y + dy[cnt];
		if(b >= w || b < 0)
		{
			cnt = (cnt + 1) % 3;
			a = x + dx[cnt], b = y + dy[cnt];
		}
		x = a, y = b;
	}
	
	for(int i = 0; i < 10000 / w; i++)
	{
		for(int j = 0; j < w; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	
	return 0;
} 
