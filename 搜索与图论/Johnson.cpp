#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;
struct Node{
	PII gc;
	int xh;
}g[N];

bool cmp(Node a, Node b)
{
	PII aa = a.gc, bb = b.gc;
	return min(aa.second, bb.first) > min(aa.first, bb.second);
}

int main()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i ++ )
	{
		cin >> g[i].gc.first;
	}
	
	for(int i = 0; i < n; i ++ )
	{
		cin >> g[i].gc.second;
	}
	
	for(int i = 0; i < n; i ++ )
	{
		g[i].xh = i + 1;
	}
	
	sort(g, g + n, cmp);
	
	int t = 0, res = 0;
	for(int i = 0; i < n; i ++ )
	{
		t += g[i].gc.first;
		res = max(res, t) + g[i].gc.second;
	}
	
	cout << res << endl;
	
	for(int i = 0; i < n; i ++ )
	{
		cout << g[i].xh << " ";
	}
	
	return 0;
}
