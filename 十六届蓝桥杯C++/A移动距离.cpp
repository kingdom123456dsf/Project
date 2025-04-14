#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	//需要先走到x = 705.581321,再计算弧度走到点(233, 666) 
	int res = 0;
	double a = 233, b = 666;
	double r = sqrt(a * a + b * b);
	printf("半径为:%lf\n", r);
	double w = 666.0 / 233.0;
	printf("弧度为:%lf\n", atan(w));
	double pi = acos(-1);
	printf("角度为:%lf\n", atan(w) * 180 / pi);
	printf("答案为:%lf",  70.72 * pi * r / 180  + r);
	//弧度角为70.717618255317496200585716773196°
	//弧长为 n2πr/360 ,n为弧度角 
	
	return 0;
}
