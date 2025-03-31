#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double length = 23333333;
	double res = 11625907.5798;
	double zero = 0, one = 0;
	
	for(int i = 1; i < length / 2; i ++ )//0出现次数
	{
		double zerotime = i / length;
		double onetime = (length - i) / length;
		double ans = i * (-zerotime) * log2(zerotime) + (length - i) * (-onetime) * log2(onetime);
		
		if(ans > 11625907.5 && ans < 11625907.6)
		{
			cout << i;
			break;
		}
	} 
	
	return 0;
} 
