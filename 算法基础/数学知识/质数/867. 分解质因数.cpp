#include<iostream>

using namespace std;

void divide(int x)
{
	for(int i = 2; i <= x / i; i ++ )
	{
		if(x % i == 0)//��2��ʼ����ö�ٵ���һ������С������ 
		{
			int s = 0;
			while(x % i == 0) x /= i, s ++;
			cout << i << " " << s << endl;
		}
	}
	if(x > 1) cout << x << " " << 1 << endl;//ʣ�µ�������1����һ����ʣ�µ�һ����һ�������� 
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	
	while(n -- )
	{
		int x;
		cin >> x;
		
		divide(x);//�ֽ������� 
	}	
	
	return 0;
}
