#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010;
int q[N], v[N];
bool st[N];
int n, x;

int main()
{
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> q[i] >> v[i];
	
	int res = 0;
	int cnt = 0;//�洢ִ�в���
	int e = 1, d = 1;//��ʼ���������߷���
	while(cnt < 13 * 2 * N)//�����������޷�ֹ��ѭ�� 
	{
		if(q[x])//������ڻ�Ŀ�� 
		{
			if(e >= v[x] && !st[x]) 
			{
				st[x] = true;
				res++;
			}
		}
		else e += v[x], d = -d;
		x += e * d;
		cnt++;
		if(x < 1 || x > n) break;
	} 
	
	cout << res << endl;
	
	return 0;
}
