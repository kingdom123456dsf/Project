#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

vector<PII> q;
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		q.push_back({l, r});
	}
	
	sort(q.begin(), q.end());
	
	int res = 1, ed = q[0].y;
	for(int i = 0; i < n; i ++ )
	{
		if(ed < q[i].x)
		{
			res ++;
			ed = q[i].y;
		}
	}
	
	printf("%d", res);
	
	return 0;
}
