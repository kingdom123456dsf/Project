#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int dx = 15, dy = 17;
	
	int t = 2000;
	while((t * dx) % 343720 != 0 || (t * dy) % 233333 != 0) t ++;
		
	double x = t * dx, y = t * dy;
	double res = x * x + y * y;
	printf("%.2lf", 2 * sqrt(res)); 
	
	return 0;
}
