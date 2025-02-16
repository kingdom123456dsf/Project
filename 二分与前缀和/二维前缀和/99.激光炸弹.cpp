#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 5002;//ע����Ϊ�������궼+1�ˣ����Բ���5001��Խ��

int s[N][N];//�Ż���ֱ��ʹ��ǰ׺�������ȴ洢������һ���ռ�ռ�� 
int n, m;//�������� 

int main(){
	int cnt, r;
	cin >> cnt >> r;
	r = min(r,5001);
	
	n = m = r;
	for(int i = 0; i < cnt; i++)
	{
		 int x, y, w;
		 cin >> x >> y >> w;
		 x++,y++;//��Ϊ���ӣ�1,1����ʼ�������˸�ÿ���������1
		 n = max(n, x);
		 m = max(m, y);
		 s[x][y] += w;
	}
	
	for(int i = 1; i <= n; i++)//��ǰ׺�� 
	{
		for(int j = 1;j <= m; j++)
		{
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	
	int res = 0;
	for(int i = r;i <= n;i++)
	{
		for(int j = r;j <= m; j++)
		{
			res = max(s[i][j] - s[i][j - r] - s[i - r][j] + s[i - r][j - r],res);
		}
	}
	
	cout << res << endl;
	return 0;
}
