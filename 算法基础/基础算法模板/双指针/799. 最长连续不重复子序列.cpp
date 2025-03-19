#include<iostream>

using namespace std;

const int N = 100010;
int a[N], cnt[N];
int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	
	int res = 0;
	for(int i = 0, j = 0; i < n; i ++)
	{
		cnt[a[i]] ++;
		while(j < i && cnt[a[i]] > 1)//双指针 
		{
			cnt[a[j]] --;//减去删掉的数的出现次数 
			j ++;//向右移，区间缩短 
		}
		res  = max(res, i - j + 1);
	}
	
	cout << res << endl;
	
	return 0;
}
