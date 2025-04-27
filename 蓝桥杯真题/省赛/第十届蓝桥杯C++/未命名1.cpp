#include<iostream>

using namespace std;

int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_valid(int x)
{
	int year = x / 10000;
	int month = x % 10000 / 100;
	int day = x % 100;
	
	if(month < 1 || month > 12 || day < 1 || day > 31) return false;
	
	if(month != 2)
	{
		if(day > days[month]) return false;
	}
	else
	{
		bool deap = year % 4 == 0 && year % 100 || year % 400 == 0;
		if(day > days[2] + deap) return false;
	}
	
	return true;
}

int main()
{
	int date1, date2;
	cin >> date1 >> date2;
	
	int res = 0;
	for(int i = date1; i <= date2; i ++ )
	{
		if(is_valid(i))//是合法的日期 
		{
			//判断是否回文日期 
			int d1 = i / 10000000;
			int d2 = i % 10000000 / 1000000;
			int d3 = i % 1000000 / 100000;
			int d4 = i % 100000 / 10000;
			int d5 = i % 10000 / 1000;
			int d6 = i % 1000 / 100;
			int d7 = i % 100 / 10;
			int d8 = i % 10;
			if(d1 == d8 && d2 == d7 && d3 == d6 && d4 == d5) res ++;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
