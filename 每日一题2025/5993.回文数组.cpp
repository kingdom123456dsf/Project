#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int a[N], b[N];

int main()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	
	for(int i = 1; i <= n / 2; i ++ )
	{
		b[i] = a[n - i + 1] - a[i];//构造对称模型 
	}
	
	int res = 0;
	for(int i = 1; i <= n / 2; i ++ )
	{
		if(b[i] > 0 && b[i + 1] > 0)
		{
			if(b[i] >= b[i + 1])
			{
				res += b[i];
				i ++ ;//若是前面的数大于后面的数，则操作两个数，第二个数可以到0，下一次跳过第二个数从下一个数开始就可以 
			}
			else if(b[i] < b[i + 1])
			{
				res += b[i]; 
				b[i + 1] -= b[i];//若是小于，则给第二个数减去第一个数即可
			}
		}
		else if(b[i] < 0 && b[i + 1] < 0)
		{
			if(b[i] <= b[i + 1])
			{
				res += abs(b[i]);
				i ++ ;
			}
			else if(b[i] > b[i + 1])
			{
				res += abs(b[i]); 
				b[i + 1] -= b[i];
			}
		}
		else res += abs(b[i]);//若是前后符号不同，则只能操作当前 
	}
	
	cout << res << endl;
	
	return 0;
}
