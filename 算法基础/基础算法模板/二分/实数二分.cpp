#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	double x;
	cin >> x;
	
	double l = -10000, r = 10000;
	while(r - l > 1e-7)//保留六位，多留一位 
	{
		double mid = (l + r) / 2;
		if(mid * mid * mid > x) r = mid;
		else l = mid;
	}
	printf("%lf\n", r);
	
	return 0;
}
