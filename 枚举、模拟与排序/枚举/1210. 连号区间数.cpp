#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 10010, INF = 1e8;
int a[N];
int n;

int main()
{
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	
	int res = 0;
	for(int i = 0;i < n;i++)
	{
		int maxv = -INF, minv = INF;
		for(int j = i;j < n;j++)
		{
			maxv = max(maxv, a[j]);
			minv = min(minv, a[j]);
			if(maxv - minv == j - i) //若是长度为j - i + 1的区间的最大最小值差为j - i则符合条件 
				res++;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
