#include<iostream>
#include<algorithm>

using namespace std;

const int N = 310;
int s[N];//ǰ׺��
int f[N][N];//i��j����С���� 

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> s[i], s[i] += s[i - 1];
	
	for(int len = 2; len <= n; len ++ )//ö�����䳤��
	{
		for(int i = 1; i + len - 1 <= n; i ++ )//������˵�
		{
			int j = i + len - 1;//�����Ҷ˵�
			f[i][j] = 1e8;//��һ�����ֵ
			for(int k = i; k <= j - 1; k ++ )
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]); 
			} 
		} 
	} 
	
	cout << f[1][n] << endl;//1��n����С���� 
	
	return 0;
}
