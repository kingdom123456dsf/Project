#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 200003;//值域两倍的第一个质数 
const int null = 0x3f3f3f3f; 
int h[N];
int n;

int find(int x)//找到x映射到哈希函数的坐标
{
	int k = (x % N + N) % N;
	
	while(h[k] != null && h[k] != x)//不会死循环(每一个位置都有人)，因为开到了两倍 
	{
		k ++ ;
		if(k == N) k = 0;//若是到末尾了，则从头开始 
	}
	
	return k;
} 

int main()
{
	memset(h, 0x3f, sizeof h);//初始化，因为最大也没1e9大 
	
 	scanf("%d", &n);
 	
 	while(n -- )
 	{
 		char op[2]; int x;
 		scanf("%s%d", op, &x);
 		
 		if(*op == 'I') h[find(x)] = x;
 		else 
 		{
 			if(h[find(x)] != null) puts("Yes");
 			else puts("No");
		}
 	}
	
	return 0;
}
