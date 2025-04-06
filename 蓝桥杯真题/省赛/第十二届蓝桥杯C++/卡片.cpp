#include<iostream>

using namespace std;

int main()
{
	//x张卡片，可以有x(x - 1) / 2 + x种组合情况
	int target;
	cin >> target;
	
	int res = 0;
	for(int i = 2; i < target; i ++ )
	{
		int x = i * (i - 1) / 2 + i;
		if(x < target) continue;
		else
		{
			res = i;
			break;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
