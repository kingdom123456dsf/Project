#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
LL a[N], pre[N], p[N], MOD = 1e9 + 7;
//pre����ǰi�������Ľ��,p����3^i����

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	
	p[0] = 1;//3��0���ݵ���1 
	for(int i = 1; i <= n; i ++ )//ǰ׺��˼�� 
	{
		pre[i] = pre[i - 1] ^ a[i] % MOD;//�洢ǰi�������Ľ�� 
		p[i] = p[i - 1] % MOD * 3 % MOD;//����3��i���� 
	}
	
	LL ans = pre[n];//ȫ������������� 
	for(int i = 1; i <= n - 1; i ++ )//ֻ��n - 1��λ�÷Ų����� 
	{
		ans = ans % MOD + pre[i] * (2 * p[n - 1 - i) % MOD;
	}
	cout << (ans % MOD + MOD) % MOD << endl;//Ϊ�˷�ֹ���Ǹ��� 
	
	return 0;	
} 
