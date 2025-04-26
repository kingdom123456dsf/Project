#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 110;
char g[N][N];
int w, h;

//LANQIAO 7位数组,数组从0开始，到6，mod7 
char str[7] = {'L', 'A', 'N', 'Q', 'I', 'A', 'O'};

int main()
{
	cin >> h >> w;//高、宽(行、列) 
	//第一行从LANQIAO按顺序开始，之后 每一行向后偏移一位，若是到头则模除一下就可以
 	for(int i = 1; i <= h; i ++ )
 	{
 		int cnt = i - 1;
 		for(int j = 1; j <= w; j ++ )//列数 
 		{
 			g[i][j] = str[cnt % 7];
 			cnt = (cnt + 1) % 7;
		}
	}
	
	int res = 0;
	for(int i = 1; i <= h; i ++ )
	{
		for(int j = 1; j <= w; j ++ )
		{
			if(g[i][j] == 'A') res ++;
		}
	}
	
	cout << res << endl;
	
	
	return 0;
}
