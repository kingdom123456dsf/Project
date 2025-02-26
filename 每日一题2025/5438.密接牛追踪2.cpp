#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int N = 300010;
vector<int> ans;
int n;
char s[N];

int main()
{
 	scanf("%d%s", &n, s);
 	
 	int r = n;//子区间长度先设为n 
 	for(int i = 0; i < n; i++)
 	{
 		if(s[i] == '0') continue;//若没被感染
		int j = i + 1;
		while(j < n && s[j] == '1') j++;//双指针 
		//默认c位于中间 
		int c = j - i;//子区间长度
		int d = (c - 1) / 2 ;//2d + 1 = c
		//c位于两端 
		if(!i || j == n) d = c - 1;
		r = min(r, d);//得到最大的天数(木桶原理，只能取最短的那一条)
		ans.push_back(c); 
		
		i = j;//！！！注意直接从当前子区间的右边开始即可(右边第一个为0) 
	}
	
	int res = 0;
	for(auto c : ans)
	{
		//c除2r+1向上取整 
		res += (c + 2 * r + 1 - 1) / (2 * r + 1);
	}
	
	printf("%d", res);
	
	return 0;
}
