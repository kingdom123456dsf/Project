#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{	
	int res = 0;
	//���ӷ�ĸ��λ�ÿ��Խ���������ö�ٳ�һ�����������ֶ�����2������
	for(int i = 1; i <= 2020; i ++ )
	{
		int j = i;
		while(j <= 2020)
		{
			if(__gcd(i, j) == 1)
			{
				res ++;
			}
			j ++;
		}
	} 
	
	//��Ϊ1/1�����������Σ��ʽ����һ�� 
	cout << res * 2 - 1 << endl;	
	
	return 0;
}
