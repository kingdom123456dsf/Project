#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int n, m;
int h[N], cnt;//h代表模拟堆的数组

void down(int u)//相当于递归的过程 
{
	int t = u;//代表最小元素下标
	if(u * 2 <= cnt && h[t] > h[u * 2]) t = u * 2;//大于左子结点
	if(u * 2 + 1 <= cnt && h[t] > h[u * 2 + 1]) t = u * 2 + 1;//右子结点
	
	if(t != u)//代表下标交换了 
	{
		swap(h[t], h[u]);
		down(t);
	}  
}

int main()
{
 	cin >> n >> m;
 	for(int i = 1; i <= n; i ++ ) cin >> h[i];
 	cnt = n;
 	
 	//可以从n/2开始down操作，时间复杂度O(n) 
 	for(int i = n / 2; i >= 1; i -- ) down(i);//实现堆结构 
	
	while(m -- )
	{
		cout << h[1] << " ";
		h[1] = h[cnt];//用尾元素覆盖首元素 
		cnt -- ;//删除尾元素空间 
		down(1); 
	}
	
	return 0;
} 
