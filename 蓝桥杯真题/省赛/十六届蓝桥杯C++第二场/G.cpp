#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long LL;

const int N = 1010;
char g[N][N];
int n, m;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//�������� 

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
	{
		string s;
		cin >> s;
		for(int j = 1; j <= m; j ++ )
		{
			g[i][j] = s[j - 1];//���������һ����������ȥ 
		}
	}

	LL ans = 0;//��¼���Ĵ� 
	for(int k = 1; k <= n; k ++ )//Ҫ��ת���ٴ���
	{
		LL res = 0;//����һ�ַ����Ĵ� 
		for(int i = 1; i <= n; i ++ )
		{
			for(int j = 1; j <= m; j ++ )
			{
				int cnt = 0;//��ͬ�ĸ��� 
				for(int d = 0; d < 4; d ++ )//�鿴���������м�����ͬ�� 
				{
					int x = i + dx[d], y = j + dy[d];
					if(x > 0 && x <= n && y > 0 && y <= m)
					{
						if(g[i][j] == g[x][y]) cnt ++;
					}
				}
				res += (LL)cnt * cnt;
			}
		}
		ans = max(ans, res);
		
		for(int j = 1; j <= n; j ++ )//��ת�� 
		{
			if(g[k][j] == '1') g[k][j] = '0';
			else g[k][j] = '1';
		}
	}
	
	//���һ�з�ת��û��ͳ��
	LL res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
		{
			int cnt = 0;//��ͬ�ĸ��� 
			for(int d = 0; d < 4; d ++ )//�鿴���������м�����ͬ�� 
			{
				int x = i + dx[d], y = j + dy[d];
				if(x > 0 && x <= n && y > 0 && y <= m)
				{
					if(g[i][j] == g[x][y]) cnt ++;
				}
			}
			res += (LL)cnt * cnt;
		}
	}
	ans = max(ans, res); 
	
	cout << ans << endl;
	
	return 0;
}
