#include<iostream>

using namespace std;

typedef long long LL;

int main()
{
	// 24 * 60 * 60一天的秒数 86400
	//注意题目给的是毫秒数，所以还得乘上1000 ,86400000
	LL time;
	scanf("%lld", &time);
	time %= (24 * 60 * 60 * 1000);//得到一天内的毫秒数
	
	LL h = time / (60 * 60 * 1000);//时
	time %= (60 * 60 * 1000);//一天分秒的毫秒数
 	
	LL m =  time / (60 * 1000);//分
 	time %= (60 * 1000);
 	
	 LL s = time / 1000;//秒 
	  
	printf("%02lld:%02lld:%02lld", h, m, s);
	
	return 0;
}
