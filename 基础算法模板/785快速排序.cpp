#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N];
int n;

void quick_sort(int q[], int l, int r)
{
	if(l >= r) return;//边界问题(写成l == r也可以)
	
	int x = q[l + r >> 1];//可以是l, l + r >> 1, r//但是需要注意后续递归的死循环问题 
	int i = l - 1, j = r + 1;//这是因为每次都先往中间移1，所以左右两边应该多留一个位置，以避免边界问题
 	while(i < j)
 	{
 		do i ++; while(q[i] < x);
 		do j --; while(q[j] > x);
 		//先一直向中间移直到碰见不符合条件的 
 		if(i < j) swap(q[i], q[j]);
	}
	
	quick_sort(q, l, j);//递归对左右两边排序 
	quick_sort(q, j + 1, r);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &q[i]);//输入
	
	quick_sort(q, 0, n - 1);
	
	for(int i = 0; i < n; i++) printf("%d ", q[i]); 
	
	return 0;
}
