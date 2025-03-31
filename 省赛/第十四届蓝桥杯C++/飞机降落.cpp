#include<iostream>
#include<vector>

using namespace std;

struct plane{
	int t, d, l;//�������������ʱ�� 
};

const int N = 15;
vector<plane> q;
bool flag;//�ж��Ƿ�ȫ����ȫ����
bool st[N];//��ʾ��ǰ�ɻ��Ƿ��� 
int x;//x�ܷɻ� 

void dfs(int u, int last)//����ɻ�����, ����ʱ��
{
	if(u == x)
	{
		flag = true; 
		return;
	}
	
	for(int i = 0; i < x; i ++ )
	{
		if(!st[i] && q[i].t + q[i].d >= last)
		{
			st[i] = true;//��ǰ�ɻ�����
			
			dfs(u + 1, max(last, q[i].t) + q[i].l);//���� 
			
			st[i] = false;//�ָ��ֳ� 
		}
	}
} 

int main()
{
	 int n;
	 cin >> n;
	 while(n -- )
	 {
	 	q.erase(q.begin(), q.end());//������� 
	 	cin >> x;//x�ܷɻ� 
	 	for(int i = 0; i < x; i ++ )
	 	{
	 		int t, d, l;
	 		cin >> t >> d >> l;
	 		q.push_back({t, d, l});
		}
		
		flag = false;
		dfs(0, 0);
		
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;		
	 }
	
	
	return 0;
}
