#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long LL;

/*bool check(int x)
{
	for(int i = 1; i <= x; i ++ )
	{
		for(int j = i + 1; j <= x; j ++ )
		{
			int sum = 0;
			for(int k = i; k <= j; k ++ )
			{
				sum += k;
			}
			if(sum == x) return true;
		}
	}
	return false;
}*/

bool is_valid(LL x)//��2�Ĵ��ݾͷ���true 
{
	return (x & (x - 1)) == 0;
}

int main()
{
	//�Ҳ��̺�ʫ���
	/*for(int i = 1; i < 5000; i ++ )//����ҹ��� 
	{
		if(!check(i)) cout << "��ʫ��:" << i << endl;
	}*/
	int n;
	cin >> n;
	
	int res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		LL x;
		cin >> x;
		if(is_valid(x)) res ++;
	}
	
	cout << res << endl;
	
	return 0;
}
