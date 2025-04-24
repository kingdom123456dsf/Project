#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 20, M = 1 << N;
int f[M][N];
int w[N][N];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++ )
	{
		for(int j = 0; j < n; j ++ )
		{
			cin >> w[i][j];
		}
	}
	
	memset(f, 0x3f, sizeof f);
	f[1][0] = 0;//��ʾ����0����,ֻ��1����ʶ�����Ҳ��1(f[1][0]) 
	
	//ö������״̬ 
	for(int i = 0; i < 1 << n; i ++ )
	{
		for(int j = 0; j < n; j ++ )
		{
			if(i >> j & 1)//j�����״̬��
			{
				for(int k = 0; k < n; k ++ )//��һ��
					if(i >> k & 1)//��һ���ĵ�Ҳ����״̬��
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]); 
			} 
		}
	}
	
	cout << f[(1 << n) - 1][n - 1] << endl;
	
	return 0;
}
