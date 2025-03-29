#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define l first
#define r second

using namespace std;

typedef pair<int, int> PII;

int n;
vector<PII> q;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i ++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		q.push_back({l, r});
	}
	
	//左端点排序 
	sort(q.begin(), q.end());
	
	//小根堆，堆顶为最小值 Max_r中的最小r 
	priority_queue<int, vector<int>, greater<int>> heap;
	for(int i = 0; i < n; i ++ )
	{
		auto t = q[i];
		if(heap.empty() || t.l <= heap.top())//为空或者有交点，新开一个区间 
		{
			heap.push(t.r);
		}
		else//若是无交点 
		{
			heap.pop();//更新右端点到当前区间的右端点
			heap.push(t.r); 
		}
	}
	
	printf("%d\n", heap.size());
	
	return 0;
}
