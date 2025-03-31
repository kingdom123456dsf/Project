#include<iostream>
#include<vector>

using namespace std;

struct plane{
	int t, d, l;//到达，盘旋，降落时长 
};

const int N = 15;
vector<plane> q;
bool flag;//判断是否全部安全降落
bool st[N];//表示当前飞机是否降落 
int x;//x架飞机 

void dfs(int u, int last)//降落飞机数量, 降落时间
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
			st[i] = true;//当前飞机降落
			
			dfs(u + 1, max(last, q[i].t) + q[i].l);//降落 
			
			st[i] = false;//恢复现场 
		}
	}
} 

int main()
{
	 int n;
	 cin >> n;
	 while(n -- )
	 {
	 	q.erase(q.begin(), q.end());//清空容器 
	 	cin >> x;//x架飞机 
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
