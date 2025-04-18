#include<iostream>

using namespace std;

const int N = 2010, MOD = 1e9 + 7;
int c[N][N];

void init()//Ԥ��������е������ 
{
	for(int i = 0; i < N; i ++ )
	{
		for(int j = 0; j <= i; j ++ )
		{
			if(!j) c[i][j] = 1;//��C(i, 0)����ǰ�����Ϊ1
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD; 
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	init();//Ԥ����O(N^2) 
	
	while(n -- )
	{
		int a, b;
		cin >> a >> b;
		
		cout << c[a][b] << endl;
	}
	
	
	return 0;
}
