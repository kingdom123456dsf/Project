#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;
int f[N][365 * 24 * 60];

struct Node{
	int m, c;
}node[N];

bool cmp(Node x, Node y){
	return x.m < y.m;
}

int main()
{
	int n, k;
	cin >> n >> k;//m为最大时限 
	
	for(int i = 1; i <= n; i ++ ) cin >> node[i].m;
	for(int i = 1; i <= n; i ++ ) cin >> node[i].c;
	
	sort(node + 1, node + n + 1, cmp);
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = k - node[i].m; j >= node[i].m; j -- )
		{
			f[i][j] = max(f[i - 1][j], f[i - 1][j - node[i].m] + node[i].c);
		}
	}
	
	int res = 0;
	for(int i = 0; i <= k; i ++ ) res = max(res, f[n][i]);
	cout << res << endl;
	
	return 0;
}
