#include<iostream>

using namespace std;

int main()
{
	int w, m, n;
	cin >> w >> m >> n;
	m --, n --;
	
	int x1 = m / w, x2 = n / w;//�к�
	int y1 = m % w, y2 = n % w;//�к�
	
	//����������
	if(x1 % 2) y1 = w - 1 - y1;
	if(x2 % 2) y2 = w - 1 - y2;
	
	//�����پ���(���־���)
	cout << abs(y1 - y2) + abs(x1 - x2) << endl; 
	
	return 0;
}
