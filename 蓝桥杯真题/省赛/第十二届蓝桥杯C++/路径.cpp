#include<iostream>

using namespace std;

int f[2025];

int gcd(int a, int b)//ŷ������㷨 
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	for(int i = 1; i <= 2021; i ++ )
	{
		for(int j = i + 1; j <= i + 21; j ++ )//ö�����п����ߵ�·�� 
		{
			if(j > 2021) break;//�߳���
			
			if(f[j] == 0)//��ǰû�߹� 
				f[j] = f[i] + j / gcd(i, j) * i;//��С������
			else//�߹� 
		 		f[j] = min(f[j], f[i] + j / gcd(i, j) * i);//��̳���  
		}
	}
	
	cout << f[2021] << endl;//���Ľ���������·	
	
	return 0;
}
