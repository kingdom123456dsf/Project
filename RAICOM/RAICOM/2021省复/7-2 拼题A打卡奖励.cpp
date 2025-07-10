#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("inline")

#include <iostream>
#include <algorithm>

using namespace std;

const int N=1e3+100;
const int M=1e4+100;

int n, k;
int f[N][M];

struct Node{
	int m, c;
}node[N];

bool cmp(Node x, Node y){
	return x.m < y.m;
}

int main()
{
	
	cin >> n >> k;//m为最大时限 
	
	for(int i = 1; i <= n; i ++ ) cin >> node[i].m;
	for(int i = 1; i <= n; i ++ ) cin >> node[i].c;
	
	sort(node + 1, node + n + 1, cmp);
		
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = k; j >= 0; j -- )//剩余时间 
		{
			if(j < node[i].m) f[i][j] = f[i - 1][j];
			else f[i][j] = max(f[i - 1][j], f[i - 1][j - node[i].m] + node[i].c);
		}
	}
	
	cout << f[n][k] << endl;
	
	return 0;
}
