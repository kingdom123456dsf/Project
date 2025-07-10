#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 1010;
int cnt[N];

int main()
{
	string s;
	cin >> s;
	
	bool flag = true;//代表是加号还是减号 
	int Max = 0, Min = 0;//最大最小结果 
	for(int i = 0; i < s.size(); i ++ )
	{
		int x = 0, y = 0;//x是常数或dy前的系数 
	 	while(i < s.size() && s[i] != 'd' && s[i] != '+' && s[i] != '-')//因为数可能不止一位 
	 	{
			x = x * 10 + (s[i ++ ] - '0');	
		}
		
		if(s[i] == 'd')//证明前面是系数 
		{	
			i ++ ;//到后一位 
			
			while(i < s.size() && s[i] != '+' && s[i] != '-')//得到y 
			{
				y = y * 10 + (s[i ++ ] - '0');
			}
			
			//记录 
			if(x) cnt[y] += x;
			else//没有系数则系数为1 
			{
				x = 1;
				cnt[y] += 1;
			}
			
			if(flag)//正
			{
				Max += x * y;
				Min += x * 1;
			} 
			else
			{
				Max -= x * 1;
				Min -= x * y;
			}
			
		}
		else//加减号，证明x只是单独的常数 
		{
			if(flag)
			{
				Max += x;
				Min += x;
			}
			else
				Max -= x;
				Min -= x;
			}
		}
		
		if(s[i] == '+') flag = true;
		else flag = false;	 	
	}
	
	for(int i = 2; i <= N; i ++ )
	{
		if(cnt[i]) cout << i << " " << cnt[i] << endl;
	}
	cout << Min << " " << Max << endl;
	
	
	return 0;
}
