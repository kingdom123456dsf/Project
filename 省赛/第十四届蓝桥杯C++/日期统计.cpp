#include<iostream>
#include<cstring>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//2023平年 

bool is_valid(int month, int day)
{
	if(day <= days[month]) return true;
	else return false;
}

bool st[20][40]; 

int main()
{
	int q[100] = {5, 6, 8, 6, 9, 1, 6, 1, 2, 4, 9, 1, 9, 8, 2, 3, 6, 
	4, 7, 7, 5, 9, 5, 0, 3, 8, 7, 5, 8, 1, 5, 8, 6, 1, 8, 3, 0, 3, 7, 
	9, 2, 7, 0, 5, 8, 8, 5, 7, 0, 9, 9, 1, 9, 4, 4, 6, 8, 6, 3, 3, 8, 
	5, 1, 6, 3, 4, 6, 7, 0, 7, 8, 2, 7, 6, 8, 9, 5, 6, 5, 6, 1, 4, 0, 
	1, 0, 0, 9, 4, 8, 0, 9, 1, 2, 8, 5, 0, 2, 5, 3, 3};
	
	
	int res = 0;
	for(int i = 1; i <= 12; i ++ )//枚举月份 
	{
		for(int j = 1; j <= days[i]; j ++)//枚举日期
		{
			int date[8] = {2, 0, 2, 3, i / 10, i % 10, j / 10, j % 10};
			int t = 0;
			for(int i = 0; i < 100; i ++ )//判断当前年月日有没有出现一次 
			{
				if(q[i] == date[t]) t ++;
				
				if(t == 8)
				{
					res ++;
					break;
				}
			} 
		} 
	} 
	
	cout << res << endl;
	
	return 0;
}
