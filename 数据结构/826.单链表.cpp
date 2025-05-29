#include<iostream>

using namespace std;

const int N = 100010;
//e[]表示当前节点的值
//ne[]表示当前节点指向的节点的值（next指针是多少） 
//head表示头结点的下标 
//idx表示已经用到了哪个点 
int e[N], ne[N], head, idx;

//初始化 
void init()
{
	head = -1;
	idx = 0;//第一个结点是0 
}

//将x插入到头结点 
void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx ++;
}

//将x插入到第k结点之后 
void add(int k, int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx ++;
}

//将k结点后面的一个点删除 
void remove(int k)
{
	ne[k] = ne[ne[k]];
}

int main()
{
	init();
	
	int m; cin >> m;
	while(m --)
	{
		int x, k;
		char s;
		cin >> s;
		if(s == 'H')
		{
			cin >> x;
			add_to_head(x);
		}
		else if(s == 'D')
		{
			cin >> k;
			if(k == 0) head = ne[head];
			else remove(k - 1);
		}
		else if(s == 'I')
		{
			cin >> k >> x;
			add(k - 1, x);
		}
	}
	
	for(int i = head; i != -1; i = ne[i])
	{
		cout << e[i] << " ";
	}
	
	return 0;
}
