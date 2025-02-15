#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {

	double n;
	cin >> n;

	double l = -10000, r = 10000;
	while (r - l > 1e-8)//保留六位，通常多留两位
	{
		double mid = (l + r) / 2;
		if (mid * mid * mid > n) r = mid;
		else l = mid;
	}

	printf("%lf\n", r);

	return 0;
}
