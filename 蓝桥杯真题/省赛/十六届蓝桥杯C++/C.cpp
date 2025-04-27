#include<iostream>

using namespace std;

int main()
{
	//-1, 0 , 1
	//负数可以和整数抵消无意义
	//从0开始就可以 
	int n;
	cin >> n;
	
	int res = n;
	for(int i = 0; i < n; i ++ )
	{
		int x;
		cin >> x;
		if(x == 1) res --;//不是1就可分解 
	}
	cout << res << endl;
	
	return 0;
}
