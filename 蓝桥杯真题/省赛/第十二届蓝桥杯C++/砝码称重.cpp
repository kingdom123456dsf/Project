#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int a[N];
bool st[110][N];//记录状态
bool f[N];//记录每个总量的答案是否存在 
int n;

void dfs(int u, int sum)//第几个砝码,和答案
{
	if(st[u][sum]) return;//若是当前状态已经有了，剪枝
	st[u][sum] = true;
	
	f[sum] = true;//该答案出现过 
	
	if(u == n) return;//选完了 
	
	dfs(u + 1, sum + a[u]);//放一边 
	dfs(u + 1, sum);//不选
	dfs(u + 1, abs(sum - a[u]));//放另一边
	//由于存在答案是负数,所以加绝对值 
} 

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++ ) cin >> a[i];
	
	dfs(0, 0);//暴搜 
	
	int res = 0;
	for(int i = 1; i < N; i ++ ) if(f[i]) res ++;
	
	cout << res << endl;
	
	return 0;
}
