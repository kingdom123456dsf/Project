#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N], tmp[N];
int n;

void merge_sort(int q[], int l, int r)
{
	if(l >= r) return;//若是只有一个数了，return
	
	int mid = l + r >> 1;//找到中点 
	
	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);//递归左右两边
	
	//归并(合二为一)
	int k = 0, i = l, j = mid + 1;//两个区间左端点的指针 
	while(i <= mid && j <= r)//未超出左右两边边界范围 
		if(q[i] <= q[j]) tmp[k ++] = q[i ++];//默认要是两数相等，先存上区间 
		else tmp[k ++] = q[j ++];
	while(i <= mid) tmp[k ++] = q[i ++];//若是一边指针到头，将另一边按顺序存入
	while(j <= r) tmp[k ++] = q[j ++];
	
	for(int i = l, k = 0; i <= r; i++, k++) q[i] = tmp[k];//存回原数组 
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)scanf("%d", &q[i]);
	
	merge_sort(q, 0, n - 1);
	
	for(int i = 0; i < n; i++) printf("%d ", q[i]); 
	
	return 0;
}
