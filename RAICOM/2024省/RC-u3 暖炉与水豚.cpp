#include<iostream>

using namespace std;

const int N = 1010;
char g[N][N];
int n, m;

bool find(int x, int y, char c)
{
	//周围8个方向 
	for(int i = x - 1; i <= x + 1; i ++ )
		for(int j = y - 1; j <= y + 1; j ++ )	
			if(i > 0 && i <= n && j > 0 && j <= m)
				if(g[i][j] == c) return true;
	return false; 			
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
			cin >> g[i][j];		
	
	int cnt = 0;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
			if(g[i][j] == 'w')//找到暖水豚
				if(!find(i, j, 'm'))//没有暖炉	   
					for(int a = i - 1; a <= i + 1; a ++ )
						for(int b = j - 1; b <= j + 1; b ++ )
							if(a > 0 && a <= n && b > 0 && b <= m && g[a][b] == '.')
								 if(!find(a, b, 'c'))//则空地藏了暖炉
								 {
								 	cout << a << " " << b << endl;
								 	cnt ++ ;
								 }		
	
	if(!cnt) cout << "Too cold!" << endl;
	
	return 0;
}
