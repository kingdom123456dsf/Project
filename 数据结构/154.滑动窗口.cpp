#include<iostream>
#include<cstdio>

using namespace std;

const int N = 1e6 + 10;
int a[N], q[N];//q���д���������±� 
int n, k;

int main()
{
 	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
	
	int hh = 0, tt = -1;//ͷ��β
	for(int i = 0; i < n; i ++ )
	{
		//���в�Ϊ��
		if(hh <= tt && i - k + 1 > q[hh]) hh ++;  //�����׳�����,hh��1 
		
		while(hh <= tt && a[q[tt]] >= a[i]) tt --;//����β������,tt��1(��Ҫ��ǰ��β) 
		q[ ++ tt] = i;							  //�±�ӵ���β 
		
		if(i >= k - 1) printf("%d ", a[q[hh]]); 	  //������ 
	} 
	puts("");
		
	hh = 0, tt = -1;//ͷ��β
	for(int i = 0; i < n; i ++ )
	{
		//���в�Ϊ��
		if(hh <= tt && i - k + 1 > q[hh]) hh ++;  //�����׳�����,hh��1 
		
		while(hh <= tt && a[q[tt]] <= a[i]) tt --;//����β������,tt��1(��Ҫ��ǰ��β) 
		q[ ++ tt] = i;							  //�±�ӵ���β 
		
		if(i >= k - 1) printf("%d ", a[q[hh]]); 	  //������ 
	} 
	puts("");
	
	return 0;
} 
