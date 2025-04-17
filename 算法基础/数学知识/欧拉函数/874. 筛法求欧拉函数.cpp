#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int primes[N], cnt;//������
bool st[N];
int phi[N];//�����Ӹ�����ŷ������

void get_eulers(int n)
{
	phi[1] = 1;//1��������ֻ���Լ� 
	for(int i = 2; i <= n; i ++ )//��2 ~ n ������ 
	{
		if(!st[i])
		{
			primes[cnt ++ ] = i;//��ǰΪ������
			phi[i] = i - 1;//��Ϊ��ǰΪ����������ô������������������i - 1 
		}
		for(int j = 0; primes[j] <= n / i; j ++ )
		{
			st[primes[j] * i] = true;
			if(i % primes[j] == 0)
			{
				phi[i * primes[j]] = phi[i] * primes[j];
				break;
			} 
			phi[i * primes[j]] = phi[i] * (primes[j] - 1);
		}
	}
}
 

int main()
{
	int n;
	cin >> n;
	
	get_eulers(n);//��1 ~ nÿ�����������Ӹ���
	
 	LL res = 0;
 	for(int i = 1; i <= n; i ++ )
 	{
 		res += phi[i];
	}
	cout << res << endl;
	
	return 0;
}
