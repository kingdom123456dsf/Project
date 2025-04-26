#include<iostream>

using namespace std;

//从0开始 

int main()
{	
	for(int i = 1; i <= 5555555; i ++ )
	{
		long long sum = 0;
		//注意是加9，一共10个数 
		for(int j = i; j <= i + 9; j ++ )
		{
			sum += j;
		}
		if(sum == 5555555)
		{
			cout << "Yes" << endl;
			break;
		}
	}
	
	
	return 0;
}
