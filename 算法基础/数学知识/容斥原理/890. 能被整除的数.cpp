#include<iostream>
#include<algorithm>

using namespace std;

const int N = 18;
typedef long long LL;
LL q[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++ ) cin >> q[i];
	
	int res = 0;
	for(int i = 1; i < 1 << m; i ++ )//ö��ÿһ������ѡ�Ͳ�ѡ�������(�����Ʊ�ʾ)
	{
		int t = 1;//��ǰ�����ĳ˻�(��n/t��ȡ�����ǵ�ǰ�ı����ĸ���)
		int s = 0;//ѡ�еļ������� 
		
		for(int j = 0; j < m; j ++ )//ö�ٳ�ÿһλ�����
		{
			if(i >> j & 1)//����ǰλѡ 
			{
				if((LL)t * q[j] > n)//������Χ�� 
				{
					t = - 1;
					break;
				}
				else
				{
					t *= q[j];
					s ++;//��ǰѡ�еļ������� 
				}
			}
		} 
		
		if(t == -1) continue;//��ʾ��ǰ�������
			
		if(s & 1) res += n / t;//����λ
		else res -= n / t;//ż��λ 
	} 
	
	cout << res << endl;	
	
	return 0;
}
