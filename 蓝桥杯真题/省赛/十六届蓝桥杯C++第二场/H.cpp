#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1e5 + 10;
vector<string> res;
bool st[N];
string s;

bool hui(string ss)//�ж��Ƿ��ǻ��� 
{
	int x = ss.size();
	ss = ' ' + ss;
	if(x != 1 && x % 2) return false;//�������ǻ���
	for(int i = 1; i <= x / 2; i ++ )
	{
		if(ss[i] != ss[x - i + 1]) return false; 
	}
	return true;
}

bool cmp(string a, string b)//���ֵ������ 
{
	//�϶̵���ǰ 
	if(a.size() != b.size()) return a.size() < b.size();
	else//������� 
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
	dfs(u + 1);//ѡ 
	st[u] = false; 
	
	dfs(u + 1);//��ѡ 
}

int main()
{
	//�һ��ģ�������(���˳���ܱ�) ,�ֵ������
	//�ֵ������ֻ���С����ö�٣����һ������������һ�����ֵ������� 
	//���Ĳ��������� 
	cin >> s;
		
	dfs(0);

	sort(res.begin(), res.end(), cmp);
	
	cout << res.back() << endl;
	
	return 0;
}
