#include<iostream>

using namespace std;

bool check(int x)
{
 	int cnt = 1;//λ��
	while(x)
	{
		int d = x % 10;//ȡ�����һλ��
	 	if(d % 2 != cnt % 2) return false;
	 	x /= 10, cnt++; 
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		if(check(i)) res++;
 	}
	cout << res << endl;
	
	return 0;
}
