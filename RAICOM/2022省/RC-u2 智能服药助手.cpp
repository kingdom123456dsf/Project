#include<iostream>
#include<cstring>
#include<map>

using namespace std;

const int N = 1010;
int mp[N];
int g[N];
int n, m;

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) cin >> g[i];//��ȫ��ʱ���� 
	
	memset(mp, -2, sizeof mp);
	while(m -- )
	{
		int t, k;//ʱ�̺ͷ��˼���ҩ�� 
		cin >> t >> k;
		for(int i = 1; i <= k; i ++ )
		{
			int x;
			cin >> x;//ҩ������
			
			if(mp[x] == -1) continue;//�޼��
			 
			if(mp[x] >= 0)//����֮ǰ���ù� 
			{
				if(t - mp[x] < g[x])
				{
					cout << "Don't take " << x << " at " << t << "!" << endl;
				}
				else mp[x] = t;//xҩ����tʱ�̷��� 
			}
			else mp[x] = t;//xҩ����tʱ�̷��� 
		}
	}
	
	return 0;
}
