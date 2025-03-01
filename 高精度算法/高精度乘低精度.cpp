#include<iostream>
#include<string>
using namespace std;
//高精度乘低精度

int a[250], b, c[300];
string s1;

int main()
{
	cin >> s1 >> b;
	//1.逆序存放
	int len = s1.length();
	for (int i = 0; i < len; i++)
	{
		a[len - i - 1] = s1[i] - '0';//字符型数组转换整形数组存放
	}

	//2.高精度乘低精度
	for (int i = 0; i < len; i++)
	{
		c[i] += a[i] * b;
		if (a[i] > 10)
		{
			a[i + 1] += a[i] / 10;//进位
			a[i] %= 10;//存余
		}
	}

	//3.长度进位
	if (c[len] > 0)
		len++;

	//4.去除前导零
	while (c[len - 1] == 0 && len > 1)
		len--;

	//5.逆序输出
	for (int i = 0; i < len; i++)
	{
		cout << c[i];
	}cout << endl;

	system("pause");
	return 0;
}
