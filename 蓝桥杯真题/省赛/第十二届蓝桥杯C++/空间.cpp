#include<iostream>

using namespace std;

int main()
{
	//67,108,864
	long long res = 256;//MB
	res = res * 1024;//KB
	res = res * 1024;//Byte
	//1Btye = 8bit
	//32bit = 4B
	res = res / 4;//¸öÊı
	cout << res << endl; 
	
	
	return 0;
}
