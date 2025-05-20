#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010;
int h[N], cnt;//数组模拟堆， 和记录堆中元素
int ph[N], hp[N];//坐标映射堆， 堆映射坐标
//ph(point->heap)可以获得第几个插入的元素现在在堆的哪个位置
//hp(heap->point)可以获得在堆的第n个元素存的是第几个插入的元素

void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int u)
{
	int t = u;//记录最小下标
	if(u * 2 <= cnt && h[t] > h[u * 2]) t = u * 2;//左儿子 
	if(u * 2 + 1 <= cnt && h[t] > h[u * 2 + 1]) t = u * 2 + 1;//右儿子
	
	if(u != t)
	{
		heap_swap(u, t);
		down(t);//递归 
 	} 
} 

void up(int u)
{
	while(u / 2 > 0 && h[u] < h[u / 2])//若是根节点大于它 
	{
		heap_swap(u, u / 2);
		u /= 2;
	}
}

int main()
{
	int n;
	cin >> n;
	
	int m = 0;//记录插入数 
	while(n -- )
	{
		string op;
		int k, x;
		cin >> op;
		
		if(op == "I")
		{
			cin >> x;
			h[++ cnt] = x;
			m ++ ;
			ph[m] = cnt;
			hp[cnt] = m;
			up(cnt);//因为没有在它后面的数 
		}
		else if(op == "PM") cout <<h[1] << endl;
		else if(op == "DM")
		{
			heap_swap(1, cnt);
			cnt -- ;
			down(1);//因为在堆顶了 
		}
		else if(op == "D")//删除第k个插入的数 
		{
			cin >> k;
			k = ph[k];
			heap_swap(k, cnt);
			cnt -- ;
			up(k), down(k);
		}
		else//修改第k个插入的数 
		{
			cin >> k >> x;
			k = ph[k];
			h[k] = x;
			up(k), down(k);
		}
	}
	
	return 0;
}
