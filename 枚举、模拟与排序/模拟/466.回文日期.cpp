#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_vaild(int t)
{
	int year = t / 10000;
	int month = t % 10000 / 100;//1 ~ 12
	int day = t % 100;
	
	if(!month || month > 12 || !day) return false;
	
	if(month != 2 && day > days[month] ) return false;
	
	if(month == 2)
	{
		bool date = year % 100 && year % 4 == 0 || year % 400 == 0;//判断闰年还是平年(0 or 1)
		if(day > days[month] + date) return false;
	}
	
	return true;
}

int main()
{
	int date1,date2;
	cin >> date1 >> date2;
	
	int res = 0;
	for(int i = 1000; i < 10000; i++)//枚举年份 
	{
		int t = i, x = i;
		//得到回文串 
		for(int j = 0; j < 4; j++) t = t * 10 + x % 10, x /= 10;	 	
		
		if(t >= date1 && t <= date2 && check_vaild(t)) res++;
	}
	
	cout << res << endl;
	
	return 0;
}
