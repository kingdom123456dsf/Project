#include<iostream>

using namespace std;

//存储月份的日期,默认为平年 
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//判断日期是否合法 
bool is_valid(int x)
{
	int year = x / 10000;
	int month = x % 10000 / 100;
	int day = x % 100;
	
	//先判断越界的情况 
	if(month < 1 || month > 12 || day < 1 || day > 31) return false;
	
	if(month != 2)
	{
		if(day > days[month]) return false;
	}
	else//2月 
	{
		bool deap = year % 4 == 0 && year % 100 || year % 400 == 0;//判断闰年还是平年 
		if(day > days[2] + deap) return false;	
	}
	
	return true;
}

int main()
{
	int res = 0;//千米 
	int t = 6;//记录周数,一周7天,直接给t模7即可 
	//枚举天数1月1日到10月1日
	for(int i = 20000101; i <= 20201001; i ++ )//枚举所有的日期
	{
		if(is_valid(i))//当前日期合法 
		{
			int day = i % 100;
			if(day == 1 || t == 1)
			{
				res += 2;
			}
			else
			{
				res += 1;
			}
			t = (t + 1) % 7;
		}
	} 
	cout << res << endl;	
	
	return 0;
}
