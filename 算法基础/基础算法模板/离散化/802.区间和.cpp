#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;
int a[N], s[N];//离散化数组和前缀和数组
vector<PII> add, query;
vector<int> alls;

int find(int x)//二分查找 
{
	int l = 0, r = alls.size() - 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;//映射到从1开始的数组 
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++ )
	{
		int x, c;
		cin >> x >> c; 
		add.push_back({x, c});
		alls.push_back(x);
	}
	for(int i = 0; i < m; i ++ )
	{
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		alls.push_back(l), alls.push_back(r);
	}
	
	//去重 
	sort(alls.begin(), alls.end());
	auto last = unique(alls.begin(), alls.end());
	alls.erase(last, alls.end());
	
	//处理x位置加c（映射到从1开始的数组） 
	for(auto item : add)
	{
		int x = find(item.first);
		int c = item.second;
		a[x] += c;
	}
	
	//前缀和数组,从1开始 
	for(int i = 1; i <= alls.size(); i ++ ) s[i] += s[i - 1] + a[i];
	
	for(auto item : query)
	{
		int l = find(item.first);
		int r = find(item.second);
		cout << s[r] - s[l - 1] << endl;
	}
	
	return 0;
}
