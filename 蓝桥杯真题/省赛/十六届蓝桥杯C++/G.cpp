#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int N = 1e3 + 10;
vector<int> G[N];//邻接表 
int a[N];//权值 

set<int> dfs(int p, int fa)//p代表当前节点,fa代表当前节点的父节点 
{
	//若当前为叶子结点 且 不为根节点
	//返回当前节点的权值且不选取任何节点 
	if(G[p].size() == 1 && fa != 0) return {a[p], 0};//集合中两个元素代表选或不选当前叶子结点 
	
	set<int> s = {0};//可以打包的成品单位 
	
	for(auto &it : G[p])//遍历当前节点p的邻接节点,也就是子节点 
	{
		if(it == fa) continue;//若为父节点，则跳过，避免反复访问 
		//树上dp
		auto v = dfs(it, p);//回溯(处理子树)
		set<int> tmp = s;//复制当前集合 s 到 tmp，避免在遍历 s 的过程中修改 s 导致迭代器失效
		for(auto &x : tmp)
		{
			for(auto &y : v)
			{
				if(x + y > a[p]) break;//超过运输限制 
				s.insert(x + y);//将结果存入答案集 
			}
		} 
	}
	return s;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	for(int i = 1; i <= n - 1; i ++ )//n个节点的树有n - 1条边 
	{
		int x, y;
		cin >> x >> y;
		//因为树是无向图,边是双向的,两个节点可以相互到达 
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	//从根节点开始递归 
	cout << *dfs(1, 0).rbegin();//根为1,没有父节点(为0) 
	//返回答案集中最大的那个结果
	
	return 0;
}
