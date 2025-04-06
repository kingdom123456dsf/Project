#include<iostream>
#include<cstring>

using namespace std;

typedef long long LL;

//上一次出现的位置,存的是A ~ z的ASCII码 
int last[200];

int main()
{
	string s;
	cin >> s;
	
	int n = s.size();//注意n的位置 
	s = ' ' + s;//让数组下标从1~n 
	
	LL res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		//当前元素到上一个相同元素后一位的个数 × 当前元素后可取区间的个数 
		res += (LL)(i - last[s[i]]) * (n - i + 1);//开LL防止运算爆int
		last[s[i]] = i;//更新元素的位置 
	}
	
	cout << res << endl;
	
	return 0;
}
