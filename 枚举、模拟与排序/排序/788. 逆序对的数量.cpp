#include<iostream>

typedef long long LL;

using namespace std;

const int N = 100010;
int q[N], tmp[N];
int n;

LL merge_sort(int q[], int l, int r)
{
	if(l >= r) return 0;
	
	int mid = l + r >> 1;//取中间的数 
	LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);//递归 
		
	int k = 0, i = l, j = mid + 1;
	while(i <= mid && j <= r)
		if(q[i] <= q[j]) tmp[k ++] = q[i ++];
		else{
			tmp[k ++] = q[j ++];
			res += mid - i + 1;//!!!推导的公式 
		}
	//收尾 
	while(i <= mid) tmp[k ++] = q[i ++];
	while(j <= r) tmp[k ++] = q[j ++];
	
	//给回原数组
	for(int i = l, k = 0; i <= r; i++, k++) q[i] = tmp[k]; 
	return res;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> q[i];
	
	cout << merge_sort(q, 0, n - 1) << endl;
	
	return 0;
}
