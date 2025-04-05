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
	//2 ^ 17 = 131,072,�����ֻ��17��,��ȫ�������ĸ��ڵ�����2 ^ n - 1; 
	for(int i = 1; i < 17; i ++ )
	{
		LL ans = 0;
		//ÿһ����2^(i - 1)�����,�����±����Ҳ�Ǵ�num��ʼ 
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
