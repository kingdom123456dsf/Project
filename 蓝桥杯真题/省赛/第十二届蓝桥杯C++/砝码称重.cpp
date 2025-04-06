#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 110, M = 2 * 100010;//M��������
int w[N];
bool f[N][M]; 
int n;

int main()
{
	scanf("%d", &n);
	
	//������1~n 
	int m;//������ 
	for(int i = 1; i <= n; i ++ )
	{
		scanf("%d", &w[i]);
		m += w[i];
	}
	
	f[0][0] = true;//0�����룬����Ϊ0
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 0; j <= m; j ++ )
		{
			//��Ϊ��bool 
			f[i][j] = f[i - 1][j] || f[i - 1][abs(j - w[i])] || f[i - 1][j + w[i]];
			//j - w[i]����Ϊ������abs��j + w[i]���ܳ���1e5,�����ݷ�ΧҪ*2 
		} 
	}
	
	int res = 0;
	for(int j = 1; j <= m; j ++ )
	{
		if(f[n][j]) res ++;
	}
	
	printf("%d", res);
		
	return 0;
}
