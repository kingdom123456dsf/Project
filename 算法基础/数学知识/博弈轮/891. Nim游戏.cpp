#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int res = 0;
	while(n -- )
	{
		int x;
		cin >> x;
		res ^= x;
	}
	
	//�������������0����ô���ֿ��԰�����Ϊ0��Ҳ�������ֱ�ʤ�� 
	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	
	return 0;
}
