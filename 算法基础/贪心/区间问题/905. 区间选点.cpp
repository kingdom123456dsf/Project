#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100010;
struct Range{
	int l, r;
}range[N];

bool cmp(Range a, Range b)
{
	return a.r < b.r;
}

int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++ )
	{
		int l, r;
		cin >> l >> r;
		range[i] = {l, r};
	}
	
	sort(range, range + n, cmp);
	
	int res = 0, ed = -2e9;
	for(int i = 0; i < n; i ++ )
	{
		if(range[i].l > ed)//左端点大于选点
		{
			res ++;
			ed = range[i].r; 
	 	} 
	}
	
	cout << res << endl;
	
	return 0;
}
