#include<iostream>

using namespace std;

typedef long long LL;

const int N = 20190330;
LL a[N];

LL f(LL x)
{
	if(x == 1) return 1;
	if(x == 2) return 1;
	if(x == 3) return 1;
	else return (f(x - 1) + f(x - 2) + f(x - 3)) % 10000;
}

int main()
{
	a[1] = 1, a[2] = 1, a[3] = 1;
	for(int i = 4; i < N; i ++ )
	{
		a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10000;
	}
	
	cout << a[20190324] << endl;

	return 0;
}
