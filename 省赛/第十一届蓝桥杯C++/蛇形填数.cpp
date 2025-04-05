#include<iostream>

using namespace std;

//右、左下、下、右上 
int dx[4] = {0, 1, 1, -1}, dy[4] = {1, -1, 0, 1};
int a[100][100];

int main()
{
	int d = 0;//移动方向
	int x = 0, y = 0;
	int t = 1;//斜线方向移动次数
	a[0][0] = 1;//二位数组模拟蛇形 
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
			i --;//最后会多加一位 
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
	
	cout << "第二行第二列是" << a[2 - 1][2 - 1] << endl;
	cout << "第20行第20列是" << a[20 - 1][20 - 1] << endl;

	
	
	return 0;
}
