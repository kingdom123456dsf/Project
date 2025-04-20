#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e8;
int a[N];

int jc(int x)
{
	int res = 0;
	for(int i = x; i >= 1; i -- )
	{
		res += i;
	}
	return res;
}

int main()
{
	//1 4 10 20 35
	//高度为几，就是上一个高度的个数，加上当前高度数的累加
	a[1] = 1;
	for(int i = 2; i <= 1000; i ++ )
	{
		a[i] += a[i - 1] + jc(i);
	}
	
	cout << a[494] << endl;
	cout << a[495] << endl;
	cout << *lower_bound(a, a + 1000, 20230610)<< endl;
	cout << lower_bound(a, a + 1000, 20230610) - a << endl;	
	
	
	return 0;
}
