#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>

using namespace std;

typedef long long LL;

const int N = 500010;
LL v[N], l[N], r[N];
int n, k;

void del(int x)
{
	l[r[x]] = l[x], r[l[x]] = r[x];
	v[l[x]] += v[x], v[r[x]] += v[x];
}

int main()
{
	scanf("%d%d", &n, &k);
	r[0] = 1, l[n + 1] = n;//初始化头尾指针
	//小根堆 
	priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> h;
 	for(int i = 1; i <= n; i ++ )
 	{
 		scanf("%lld", &v[i]), l[i] = i - 1, r[i] = i + 1;
 		h.push({v[i], i});
	}
	
	while(k -- )
	{
		auto t = h.top(); h.pop();
		
		if(t.first != v[t.second])
		{
			h.push({v[t.second], t.second});
			k ++;//相当于当前操作不作数 
		}
		else del(t.second);
	}
	
	int head = r[0];
	while(head < n + 1)
	{
		cout << v[head] << " ";
		head = r[head];
	}	
	
	return 0;
}
