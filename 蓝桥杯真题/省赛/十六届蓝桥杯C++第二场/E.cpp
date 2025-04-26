#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
LL a[N], b[N];
int n;

int main()
{
	//̰��˼�룺����С���������Ժ󣬱���A��С�����B��
	//�Ų���ȥ�ľ�����Ҫ�滻�� 
	
	//Ai < Bi����Ҫ�滻 
	//0���������� ����
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
	
	for(int i = 1; i <= n; i ++ ) scanf("%lld", &b[i]);
	
	sort(a + 1, a + 1 + n); 
	
	sort(b + 1, b + 1 + n);
	
	int res = 0;
	for(int i = 1; i <= n; i ++ )//ö��b 
	{
		int j = i;//��a 
		while(j <= n)
		{
			if(a[j] > b[i])//����Ҫ�� 
			{
				i ++;
				res ++;
			}
			j ++;
		}
	}
	cout << n - res << endl;
	
	return 0;
}
