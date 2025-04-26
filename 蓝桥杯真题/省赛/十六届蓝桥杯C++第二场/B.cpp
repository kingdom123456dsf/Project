#include<iostream>

using namespace std;

typedef long long LL;

const int N = 20255202;
LL s[N];

bool is_valid(int x)
{
	//可以先预处理前缀和，再枚举区间(长度为10) 
	for(int i = 1; i + 9 <= 20255202; i ++ )
	{
		//1 ~ 11,连续十个正整数 
		LL sum = s[i + 9] - s[i - 1];
		if(sum == x) return true;
		else if(sum > x) return false;
	}
	return false;
}

bool samenunm(int x)
{
	int t = 0;
	int num = x % 10;
	while(x)
	{
		t = x % 10;
		if(t != num) return false;
		x /= 10;
	}
	return true;
}

int main()
{
	//预处理前缀和
	for(int i = 1; i <= 20255202; i ++ )
	{
		s[i] = i;
	}
	for(int i = 1; i <= 20255202; i ++ )
	{
		s[i] += s[i - 1];//前缀和数组 
 	}
	
	LL res = 0;//脉冲之和 
	for(int i = 1; i <= 20255202; i ++ )
	{
		if(is_valid(i))
		{
			if(samenunm(i))
			{
				cout << i << endl;
				res += i;
			}
		}
	}
	
	cout << "答案是:" << res << endl;
	
	return 0;
}
