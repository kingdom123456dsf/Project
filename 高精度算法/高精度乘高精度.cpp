#include<iostream>
#include<string>
using namespace std;

int a[2000], b[2000], c[4000], k;
string s1, s2;

int main()
{

	cin >> s1 >> s2;
	//1.����ת������
	int len = s1.length();
	for (int i = 0; i < len; i++)
		a[len - i - 1] = s1[i] - '0';
	len = s2.length();
	for (int i = 0; i < len; i++)
		b[len - i - 1] = s2[i] - '0';

	//2.�߾��ȳ˸߾���(����ѭ��Ƕ��)
	for (int i = 0; i < s1.length(); i++)
	{
		for (int j = 0; j < s2.length(); j++)
		{
			k = i + j;
			c[k] += a[i] * b[j];//��Ҫ����+
			if (c[k] >= 10)
			{
				c[k + 1] += c[k] / 10;//��λ
				c[k] %= 10;//����
			}
		}
	}

	//3.�жϳ���
	len = s1.length() + s2.length();
	if (c[len + 1] > 0)
		len++;

	//4.ȥ��ǰ����
	while (c[len - 1] == 0 && len > 1)
		len--;
	
	//5.�������
	for (int i = 0; i < len; i++)
	{
		cout << c[len - i - 1];
	}cout << endl;


	system("pause");
	return 0;
}