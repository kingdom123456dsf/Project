#include<iostream>

using namespace std;

int main()
{
	//x�ſ�Ƭ��������x(x - 1) / 2 + x��������
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
