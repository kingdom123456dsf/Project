#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int last[N], score[N];//记录上一个有订单的时刻，记录优先级 
bool st[N];//记录是否符合条件

PII order[N];
int n, m, T;

int main()
{
 	scanf("%d%d%d", &n, &m, &T);
	 
	for(int i = 0; i < m; i++) scanf("%d%d", &order[i].x, &order[i].y);//输入
 	sort(order, order + m);//排序,pair排序是先按照第一个比较,第一个若是相同则按照第二个比较
 
 	//枚举每个订单
	for(int i = 0; i < m; )
	{
		int j = i;
		while(j < m && order[i] == order[j]) j ++;//可以判断同一时间同一店的重复情况 
		int t = order[i].x, id = order[i].y, cnt = j - i; //记录订单数量 
		i = j;
		
		score[id] -= t - last[id] - 1;//是t时刻之前的(不包括t)
		if(score[id] < 0) score[id] = 0;
		if(score[id] <= 3) st[id] = false;
		
	 	score[id] += cnt * 2;//t时刻
		if(score[id] > 5) st[id] = true; 
		
		last[id] = t; 		
	}
	
	for(int i = 1; i <= n; i++)//枚举每家店，查看是否有T时刻之间无订单的
	{
		if(last[i] < T)//因为不到T(0 ~ T - 1) 
		{
			score[i] -= T - last[i];
			if(score[i] <= 3) st[i] = false;
		}
	} 
	
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		res += st[i];
	}
	
	printf("%d", res);
	
	return 0;
}
