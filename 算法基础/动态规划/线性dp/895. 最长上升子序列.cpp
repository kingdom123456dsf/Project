#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 1010;
int a[N], f[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
	
	int res = 0;
	if(n == 1) res = 1;
	for(int i = 0; i < n; i ++ )
	{
		f[i] = 1;//һ��������ô���г��Ⱦ���1 
		for(int j = 0; j < i; j ++ )//��i֮ǰ��ĳ����Ƕ���,��ʵ����j + 1 
		{
			if(a[j] < a[i])//�ϸ񵥵����� 
			{
				f[i] = max(f[i], f[j] + 1);
				res = max(f[i], res);
			}
		}
	}
	
	cout << res << endl;
	
	return 0;
}
