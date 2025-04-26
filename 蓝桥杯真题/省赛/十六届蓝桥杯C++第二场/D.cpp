#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 110;
char g[N][N];
int w, h;

//LANQIAO 7λ����,�����0��ʼ����6��mod7 
char str[7] = {'L', 'A', 'N', 'Q', 'I', 'A', 'O'};

int main()
{
	cin >> h >> w;//�ߡ���(�С���) 
	//��һ�д�LANQIAO��˳��ʼ��֮�� ÿһ�����ƫ��һλ�����ǵ�ͷ��ģ��һ�¾Ϳ���
 	for(int i = 1; i <= h; i ++ )
 	{
 		int cnt = i - 1;
 		for(int j = 1; j <= w; j ++ )//���� 
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
