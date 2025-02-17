#include<iostream>
#include<cstdio>

using namespace std;

const int N = 1010;
int a[N][N],b[N][N],c[N][N];//三个二维数组来表示三维空间 
int n,q;

int main()
{
	scanf("%d%d", &n, &q);
	int res = 0;
	while(q--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if(++a[x][y] == n) res++;
		if(++b[y][z] == n) res++;
		if(++c[x][z] == n) res++;
		printf("%d\n", res); 
	}
		
	return 0;
}
