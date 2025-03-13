#include<iostream>

using namespace std;

int main()
{
	int w, m, n;
	cin >> w >> m >> n;
	m --, n --;
	
	int x1 = m / w, x2 = n / w;//行号
	int y1 = m % w, y2 = n % w;//列号
	
	//特判奇数行
	if(x1 % 2) y1 = w - 1 - y1;
	if(x2 % 2) y2 = w - 1 - y2;
	
	//曼哈顿距离(折现距离)
	cout << abs(y1 - y2) + abs(x1 - x2) << endl; 
	
	return 0;
}
