#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define ts first
#define id second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int cnt[N];//统计某个id出现多少次 
bool st[N];//判断是否>=k
PII logs[N];

int main()
{
	int n, d, k;
	scanf("%d%d%d", &n, &d, &k);
	
	for(int i = 0; i < n; i ++)
	{
		scanf("%d%d", &logs[i].ts, &logs[i].id);
	}
	sort(logs, logs + n);//排序
	
	for(int i = 0, j = 0; i < n; i ++)
	{
		int id = logs[i].id;
		cnt[id] ++;//统计次数 
		
		while(logs[i].ts - logs[j].ts >= d)//当区间大于等于d
		{
			cnt[logs[j].id] --;//去掉超出区间的 
	 	 	j ++;
		}
		
		if(cnt[id] >= k) st[id] = true;
	}
	
	for(int i = 0; i < N; i++)
	{
		if(st[i]) cout << i << endl;
	}
	
	
	return 0;
}
