#include<iostream>
#include<algorithm>
#include<vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

vector<PII> q;
int n;

int main()
{
	int st, ed;
	scanf("%d%d", &st, &ed);
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		q.push_back({l, r});
	}
	
	sort(q.begin(), q.end());
	
	int res = 0;
	for(int i = 0; i < n; i ++ )
	{
		int j = i, r = -2e9;
		while(j < n && q[j].x <= st)
		{
			r = max(r, q[j].y);
			j ++;
		}
		
		if(r < st)
		{
			res = -1;
			break;
		}
		
		if(r >= st)
		{
			res ++;
			st = r;
		}
		
		if(r >= ed)
		{
			break;
		}
		
		i = j - 1;
	}
	
	cout << res << endl;
	
	return 0;
}
