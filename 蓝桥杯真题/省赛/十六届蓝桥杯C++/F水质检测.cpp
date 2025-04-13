#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e6 + 10;
int a[2][N];

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int x1 = 0;
	for(int i = 0; i < s1.size(); i ++ )
	{
		if(s1[i] == '#')
		{
			x1 = i;
			break;
		}
	}
	
	int x2 = 0;
	for(int i = 0; i < s2.size(); i ++ )
	{
		if(s2[i] == '#')
		{
			x2 = i;
			break;
		}
	}
	
	int ed = 0;//�ҵ����һ���ܵ���λ��
	for(int i = s1.size() - 1; i >= 0; i -- )
	{
		if(s1[i] == '#') 
		{
			ed = max(ed, i);
			break;
		}
	}
	for(int i = s2.size() - 1; i >= 0; i -- )
	{
		if(s2[i] == '#') 
		{
			ed = max(ed, i);
			break;
		}
	}
				
	//�ҵ��������ȳ��ֹܵ�����һ�� 
	//�ӵ�һ��һ·�ߵ��ڣ����еĹܵ�һ��������ͨ
	int res = 0; 
	if(x1 <= x2)
	{
		for(int i = x1; i <= ed; i ++ )
		{
			if(s1[i] == '.') res ++;
		}
	}
	else
	{
		for(int i = x2; i <= ed; i ++ )
		{
			if(s2[i] == '.') res ++;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
