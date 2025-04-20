#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int mid[N * 2];//中点个数 ,为什么乘2,因为中点l + r / 2可能是分数,所以直接都扩大二倍就解决了这个问题
 
int main()
{
	int n, m;
	cin >> n >> m;
	
	while(n -- )
	{
		int l, r;
		cin >> l >> r;
		mid[l + r] ++ ;//直接给中点 * 2,避免分数问题 
	}
	
	for(int i = 1; i < N * 2; i ++ )
	{
		mid[i] += mid[i - 1];//前缀和数组，便于后续统计有多少中点在区间中 
	}	
	
	while(m -- )
	{
		LL res = 0;
		int l, r;
		cin >> l >> r;
		res += mid[r * 2] - mid[l * 2 - 1];
		cout << res << endl;
	}		
	
	return 0;
}
