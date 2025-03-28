#include<iostream>
#include<algorithm>
#include<set>

typedef long long LL;

using namespace std;

const int N = 1010;
LL a[N];
multiset<LL> ranges;
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		a[i] += a[i - 1];//前缀和处理 
	}
	
	//避免边界判断 
	ranges.insert(1e13), ranges.insert(-1e13);//提前加一个最大最小值
	LL res = 1e9; 
	for(int l = 1; l <= n; l ++ )//枚举右区间的左边界 
	{
		for(int i = 1; i <= l - 1; i ++)//[i, l - 1]//补充左边区间 
		{
			ranges.insert(a[l - 1] - a[i - 1]);
		}
		for(int r = l; r <= n; r ++)//右区间的右边界 
		{
			LL sum = a[r] - a[l - 1];//右区间的大小
			auto it = ranges.lower_bound(sum);//二分，找到大于等于它的最小值
		 	res = min(res, *it - sum);
		 	it --;//小于等于它的最大值
		 	res = min(res, sum - *it);
		}
	}
	
	cout << res << endl;
	
	return 0;
}
