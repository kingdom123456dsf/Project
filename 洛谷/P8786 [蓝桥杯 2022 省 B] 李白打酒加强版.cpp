#include<iostream>

using namespace std;

const int N = 110, MOD = 1e9 + 7;
int f[N][N][N];
int n, m;

int main()
{
	cin >> n >> m;
	
	f[0][0][2] = 1;//�ʼ��û�е꣬û�л���������
	for(int i = 0; i <= n; i++)//�� 
	{
		for(int j = 0; j <= m; j++)//�� 
		{
			for(int k = 0; k <= m; k++)//���оƵ��������ܱȻ��࣬��Ȼ�����Ƶ���������Ϊ0�� 
			{
				if(i && k % 2 == 0) f[i][j][k] = (f[i][j][k] + f[i - 1][j][k / 2]) % MOD;//���Ϊ��
				if(j) f[i][j][k] = (f[i][j][k] + f[i][j - 1][k + 1]) % MOD;				
			} 
		}
	}
	
	cout << f[n][m - 1][1] << endl;//���һ���ǻ�,������n���꣬m - 1�仨�� 1���� 
	
	return 0;
}
