#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1e5 + 10;
vector<string> res;
bool st[N];
string s;

bool hui(string ss)//判断是否是回文 
{
	int x = ss.size();
	ss = ' ' + ss;
	if(x != 1 && x % 2) return false;//奇数则不是回文
	for(int i = 1; i <= x / 2; i ++ )
	{
		if(ss[i] != ss[x - i + 1]) return false; 
	}
	return true;
}

bool cmp(string a, string b)//找字典序最大 
{
	//较短的在前 
	if(a.size() != b.size()) return a.size() < b.size();
	else//长度相等 
	{
		for(int i = 0; i < a.size(); i ++ )
		{
			return a[i] < b[i];
		}
	}
}

void dfs(int u)
{
	if(u > s.size())
	{
		string path;
		for(int i = 0; i < s.size(); i ++ )
		{
			if(st[i]) path += s[i];
		}
		
		if(hui(path)) res.push_back(path);
 		
		return ;
	}
	
	st[u] =  true;
	dfs(u + 1);//选 
	st[u] = false; 
	
	dfs(u + 1);//不选 
}

int main()
{
	//找回文，子序列(相对顺序不能变) ,字典序最大
	//字典序最大只需从小到大枚举，最后一个满足条件的一定是字典序最大的 
	//回文不能是奇数 
	cin >> s;
		
	dfs(0);

	sort(res.begin(), res.end(), cmp);
	
	cout << res.back() << endl;
	
	return 0;
}
