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
			res += a & 1;//1的二进制数为0000...1,所以按位与就是比较最低位是否为1 
			a = a >> 1;//右移一位 
		}
		printf("%d ", res);
	}	
	
	return 0;
}
