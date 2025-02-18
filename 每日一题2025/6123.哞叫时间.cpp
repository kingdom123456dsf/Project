#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 20010;
char s[N];
int cnt[26][26];//用来记录abb类型的出现次数 
bool check[26][26];//判断是否满足题意 
int n,f;

void update(int l, int r, int v)
{
	l = max(0, l), r = min(r , n - 1);//防止数组越界
	for(int i = l;i + 2 <= r;i++)
	{
		if(s[i] != s[i + 1] && s[i + 1] == s[i + 2])
		{
			cnt[s[i]][s[i + 1]] += v;
			if(cnt[s[i]][s[i + 1]] >= f) check[s[i]][s[i + 1]] = true;
		}
	} 
}

int main(){
	scanf("%d%d%s", &n, &f, s);
	for(int i = 0;i < n;i++) s[i] -= 'a';//转换成int,当前字母减去'a'的ASCII码
	
 	update(0, n, 1);//记录初始情况 
 	for(int i = 0;i < n;i++)
 	{
 		char t = s[i];
 		update(i - 2, i + 2, -1);//减去改变当前字符所影响的三个子串 
 		for(int j = 0;j < 26;j++)
 		{
			if(j != t) 
			{
				s[i] = j;
				update(i - 2, i + 2, 1);//记录改变后的情况 
				update(i - 2, i + 2, -1);//恢复现场 
			}
 		}
 		s[i] = t;
		update(i - 2, i + 2, 1); //恢复现场  		
	}
	
	int res = 0;
	for(int i = 0; i < 26;i++)
		for(int j = 0;j < 26;j++)
			if(check[i][j]) res++;
		
	printf("%d\n", res);	
	
	for(int i = 0;i < 26;i++)//代表a 
		for(int j =0;j < 26;j++)//代表b 
			if(check[i][j])	printf("%c%c%c\n", i + 'a', j + 'a', j + 'a');//恢复字符输出 
		
	return 0;
}
