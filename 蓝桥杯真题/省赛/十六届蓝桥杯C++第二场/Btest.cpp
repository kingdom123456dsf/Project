#include<iostream>

using namespace std;

//��0��ʼ 

int main()
{	
	for(int i = 1; i <= 5555555; i ++ )
	{
		long long sum = 0;
		//ע���Ǽ�9��һ��10���� 
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
