#include<iostream>
#include<cstdio>

using namespace std;

const int N = 1e6 + 10;
int a[N], q[N];//q队列存的是数组下标 
int n, k;

int main()
{
 	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
	
	int hh = 0, tt = -1;//头、尾
	for(int i = 0; i < n; i ++ )
	{
		//队列不为空
		if(hh <= tt && i - k + 1 > q[hh]) hh ++;  //若队首出窗口,hh加1 
		
		while(hh <= tt && a[q[tt]] >= a[i]) tt --;//若队尾不单调,tt减1(不要当前队尾) 
		q[ ++ tt] = i;							  //下标加到队尾 
		
		if(i >= k - 1) printf("%d ", a[q[hh]]); 	  //输出结果 
	} 
	puts("");
		
	hh = 0, tt = -1;//头、尾
	for(int i = 0; i < n; i ++ )
	{
		//队列不为空
		if(hh <= tt && i - k + 1 > q[hh]) hh ++;  //若队首出窗口,hh加1 
		
		while(hh <= tt && a[q[tt]] <= a[i]) tt --;//若队尾不单调,tt减1(不要当前队尾) 
		q[ ++ tt] = i;							  //下标加到队尾 
		
		if(i >= k - 1) printf("%d ", a[q[hh]]); 	  //输出结果 
	} 
	puts("");
	
	return 0;
} 
