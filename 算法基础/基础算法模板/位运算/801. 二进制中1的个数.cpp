#include<iostream>
#include<cstdio>

using namespace std;
int n, a;

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++ )
	{
		int res = 0;
		scanf("%d", &a);
		while(a)
		{
			res += a & 1;//1�Ķ�������Ϊ0000...1,���԰�λ����ǱȽ����λ�Ƿ�Ϊ1 
			a = a >> 1;//����һλ 
		}
		printf("%d ", res);
	}	
	
	return 0;
}
