#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int a[N], b[N];

int main()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	
	for(int i = 1; i <= n / 2; i ++ )
	{
		b[i] = a[n - i + 1] - a[i];//����Գ�ģ�� 
	}
	
	int res = 0;
	for(int i = 1; i <= n / 2; i ++ )
	{
		if(b[i] > 0 && b[i + 1] > 0)
		{
			if(b[i] >= b[i + 1])
			{
				res += b[i];
				i ++ ;//����ǰ��������ں����������������������ڶ��������Ե�0����һ�������ڶ���������һ������ʼ�Ϳ��� 
			}
			else if(b[i] < b[i + 1])
			{
				res += b[i]; 
				b[i + 1] -= b[i];//����С�ڣ�����ڶ�������ȥ��һ��������
			}
		}
		else if(b[i] < 0 && b[i + 1] < 0)
		{
			if(b[i] <= b[i + 1])
			{
				res += abs(b[i]);
				i ++ ;
			}
			else if(b[i] > b[i + 1])
			{
				res += abs(b[i]); 
				b[i + 1] -= b[i];
			}
		}
		else res += abs(b[i]);//����ǰ����Ų�ͬ����ֻ�ܲ�����ǰ 
	}
	
	cout << res << endl;
	
	return 0;
}
