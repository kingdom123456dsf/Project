#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010, M = 2 * N;
bool st[N];//用于记录每个点是否走过 
int h[N], e[M], ne[M], idx;//和单链表的唯一区别就是开了N个单链表 
int n;
int ans = N;//答案 

void add(int a, int b)//a点和b点相连 
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++ ;
}

//存的是删去当前点后，最大的连通块中点的个数 
int dfs(int u)
{
	st[u] = true;//标记当前点走过了 
	
	int sum = 1;//记录点的数量,当前有一个点 
	int res = 0;//记录删去当前点后连通块..... 
	//与单链表遍历一样 
	for(int i = h[u]; i != -1; i = ne[i])//只不过现在是遍历当前点的单链表
	{
		int j = e[i];//链表存的就是点 
		if(!st[j])
		{
			int s = dfs(j);
			res = max(res, s);//取删去当前点的最大情况 
			sum += s; 
		}
	} 
	res = max(res, n - sum);//当前点以上的连通块的点的数量，和当前点之下的最大 
	
	ans = min(res, ans);//答案是在所有情况的最大中，取最小 
	return sum;	
}

int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n;
	
	for(int i = 0; i < n - 1; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	
	dfs(1);//遍历点 
	
	cout << ans << endl;
	
	return 0;
}
