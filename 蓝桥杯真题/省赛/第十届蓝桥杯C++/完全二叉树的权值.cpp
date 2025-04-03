#include<iostream>
#include<algorithm>
#include<cmath>

typedef long long LL;

using namespace std;

const int N = 100010;
LL a[N];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	
	LL res = 0;
	int t = 0;
	bool flag = false;
	//2 ^ 17 = 131,072,故最多只有17层,完全二叉树的根节点数是2 ^ n - 1; 
	for(int i = 1; i < 17; i ++ )
	{
		LL ans = 0;
		//每一层有2^(i - 1)个结点,并且下标起点也是从num开始 
		int num = pow(2, i - 1);
		for(int j = num; j < num + num; j ++ )
		{
//			cout << a[j] << " ";
			ans += a[j];
			if(a[j] == 0) flag = true;
		}
//		cout << endl;
		if(ans > res)
		{
			res = ans;
			t = i;
		}
		if(flag) break;
	}
	
	cout << t << endl;
	
	return 0;
}
