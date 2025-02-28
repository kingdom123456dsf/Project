#include<iostream>
#include<cstring>
#include<algorithm>
#include<sstream>

using namespace std;

const int N = 10010;
int a[N];

int main()
{
	int cnt;
	cin >> cnt;

	char c;
	int n = 0;
	for(int k = 0; k < cnt; k++)
	{
		while(true)
		{
			cin >> a[n];
			n++;
			c = getchar();//读取数字后的一个字符(空格或换行符)
			if(c != ' ') break;//读到换行符，结束这层循环 
		}
	}
	 
	sort(a, a + n);
	int res1,res2;
	for(int i = 1;i < n;i++)
	{
	 	if(a[i] == a[i - 1]) res2= a[i];//重号
		if(a[i] == a[i - 1] + 2) res1 = a[i] - 1;//断号 
	}
	 
	cout << res1 << " " << res2 << endl;
	
	return 0;
}
