#include<iostream>
#include<string>
using namespace std;
//�߾��ȳ˵;���

int a[250], b, c[300];
string s1;

int main()
{
	cin >> s1 >> b;
	//1.������
	int len = s1.length();
	for (int i = 0; i < len; i++)
	{
		a[len - i - 1] = s1[i] - '0';//�ַ�������ת������������
	}

	//2.�߾��ȳ˵;���
	for (int i = 0; i < len; i++)
	{
		c[i] += a[i] * b;
		if (a[i] > 10)
		{
			a[i + 1] += a[i] / 10;//��λ
			a[i] %= 10;//����
		}
	}

	//3.���Ƚ�λ
	if (c[len] > 0)
		len++;

	//4.ȥ��ǰ����
	while (c[len - 1] == 0 && len > 1)
		len--;

	//5.�������
	for (int i = 0; i < len; i++)
	{
		cout << c[i];
	}cout << endl;

	system("pause");
	return 0;
}
