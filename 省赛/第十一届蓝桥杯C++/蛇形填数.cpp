#include<iostream>

using namespace std;

//�ҡ����¡��¡����� 
int dx[4] = {0, 1, 1, -1}, dy[4] = {1, -1, 0, 1};
int a[100][100];

int main()
{
	int d = 0;//�ƶ�����
	int x = 0, y = 0;
	int t = 1;//б�߷����ƶ�����
	a[0][0] = 1;//��λ����ģ������ 
	for(int i = 2; i <= 800; i ++ )
	{
		d %= 4;
		if(d == 1 || d == 3)
		{
			int temp = t;
			while(temp -- )
			{
				x = x + dx[d], y = y + dy[d];
				a[x][y] = i;
				i ++;
			}
			i --;//������һλ 
			t ++;
		}
		else
		{
			x = x + dx[d], y = y + dy[d];
			a[x][y] = i;
		}
		d ++;
	}
	
	for(int i = 0; i <= 20; i ++ )
	{
		for(int j = 0; j <= 20; j ++ )
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "�ڶ��еڶ�����" << a[2 - 1][2 - 1] << endl;
	cout << "��20�е�20����" << a[20 - 1][20 - 1] << endl;

	
	
	return 0;
}
