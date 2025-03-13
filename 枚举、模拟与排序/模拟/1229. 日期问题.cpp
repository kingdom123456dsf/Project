#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//默认平年 

bool check(int year, int month, int day)
{
	if(month > 12 || month < 1) return false;
	
	if(day > 31 || day < 1) return false;
	
	if(month != 2)
	{
		if(day > days[month]) return false;
	}
	else
	{
		int x = year % 4 == 0 && year % 100 || year % 400 == 0;//闰年为1，平年为0 
		if(day > days[month] + x) return false;
	}
	
	return true;
}

int main()
{
	int a, b, c;
	scanf("%d/%d/%d", &a, &b, &c);//scanf用于特殊读入 
	
	for(int i = 19600101; i <= 20591231; i++)
	{
		int year = i / 10000, month = i % 10000 / 100, day = i % 100;
		if(check(year, month, day))
		{
			if((year % 100 == a && month == b && day == c) ||//年月日 
		 	(year % 100 == c && month == a && day == b) ||//月日年 
		 	(year % 100 == c && month == b && day == a))//日月年 
		 	{
		 		printf("%d-%02d-%02d\n", year, month, day);
			}
		}
	}
	
	return 0;
}
