#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 12, M = 1 << N;//�����ö����Ʊ�ʾ
long long f[N][M];//��ʾ�����ڵ�i�У����ҵ�ǰ������ǰһ�������j��С��������� 
bool st[M];//��ʾ��������û�����С���������ż�������������� 
int n, m;

int main()
{
 	while(cin >> n >> m, n || m)
 	{
 		//Ԥ����st
		for(int i = 0; i < 1 << n; i ++ )
		{
		 	int cnt = 0;//����Ϊ0������
			st[i] = true;//Ĭ����ż����,��Ϊż�����������ŷ�2 * 1
			for(int j = 0; j < n; j ++ )
			{
				if(i >> j & 1)
				{
					if(cnt & 1) st[i] = false;//����
					cnt = 0; 
				}	 
				else cnt ++;
			}
			if(cnt & 1) st[i] = false;//������һ�� 
		}
		
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for(int i = 1; i <= m; i ++ )
			for(int j = 0; j < 1 << n; j ++ )	
				for(int k = 0; k < 1 << n; k ++ )
					if((j & k) == 0 && st[j | k])
			  			f[i][j] += f[i - 1][k];
						  
		cout << f[m][0] << endl;//��m�в��������С����Ϊ0�Ľ��(��Ϊ��ൽ��m - 1�У������Ǹպ÷źõ�)  
	}
	
	
	return 0;
} 
