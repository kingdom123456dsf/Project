#include<iostream>
#include<string>
using namespace std;

int a[2000], b[2000], c[4000], k;
string s1, s2;

int main()
{

	cin >> s1 >> s2;
	//1.逆序转存整数
	int len = s1.length();
	for (int i = 0; i < len; i++)
		a[len - i - 1] = s1[i] - '0';
	len = s2.length();
	for (int i = 0; i < len; i++)
		b[len - i - 1] = s2[i] - '0';

	//2.高精度乘高精度(利用循环嵌套)
	for (int i = 0; i < s1.length(); i++)
	{
		for (int j = 0; j < s2.length(); j++)
		{
			k = i + j;
			c[k] += a[i] * b[j];//不要忘了+
			if (c[k] >= 10)
			{
				c[k + 1] += c[k] / 10;//进位
				c[k] %= 10;//存余
			}
		}
	}

	//3.判断长度
	len = s1.length() + s2.length();
	if (c[len + 1] > 0)
		len++;

	//4.去除前导零
	while (c[len - 1] == 0 && len > 1)
		len--;
	
	//5.逆序输出
	for (int i = 0; i < len; i++)
	{
		cout << c[len - i - 1];
	}cout << endl;


	system("pause");
	return 0;
}