#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

int get_seconds(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}

int get_time()
{
	string line;
	getline(cin, line);//读取一行 
	
	if(line.back() != ')') line += " (+0)";//统一格式
	
	int h1, m1, s1, h2, m2, s2, d;//特殊输入处理 
	sscanf(line.c_str(), "%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
	
	return get_seconds(h2, m2, s2) - get_seconds(h1, m1, s1) + d * 24 * 3600;//d是多几天 
}

int main()
{
	int T;
	scanf("%d", &T);
	string line = "\n";//因为scanf 不会读取最后的换行符 
	getline(cin, line);//读取换行符 
	while(T --)
	{
		int time = (get_time() + get_time()) / 2;
		int month = time / 3600, minute = time % 3600 / 60, second = time % 60;
		printf("%02d:%02d:%02d\n", month, minute, second);
	}
	
	return 0;
}
