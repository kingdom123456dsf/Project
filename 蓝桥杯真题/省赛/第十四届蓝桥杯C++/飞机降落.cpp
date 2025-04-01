#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct plane{
	int t, d, l;//������������� 
}; 

const int N = 15;
bool st[N];//��ʾÿ�ܷɻ��Ƿ��� 
bool flag;//�����Ƿ����ȫ������ 
vector<plane> q;
int T;
int n;

void dfs(int u, int last)//�ڼ��ܷɻ�������ʱ��
{
	if(u == n)
	{
	    flag = true;
	    return;
	}
	
	for(int i = 0; i < n; i ++ )
	{
		if(!st[i] && q[i].t + q[i].d >= last)
		{
			st[i] = true;
			
			dfs(u + 1, max(last, q[i].t) + q[i].l);
			
			st[i] = false;
		}
	}
} 

int main()
{
	cin >> T;
	while(T -- )
	{
		q.erase(q.begin(), q.end());//��� 
		cin >> n;
		for(int i = 0; i < n; i ++ )
		{
			int a, b, c;
			cin >> a >> b >> c;
			q.push_back({a, b, c});
		}
        
        flag = false;
        dfs(0, 0);
			
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	return 0;
}
