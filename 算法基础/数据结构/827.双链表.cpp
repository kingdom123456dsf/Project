#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int e[N], l[N], r[N], idx;

void init()
{
	r[0] = 1, l[1] = 0;
	idx = 2;
}

//在k的右边插入x 
void add(int k, int x)
{
	e[idx] = x;
	r[idx] = r[k];
	l[r[k]] = idx;
	
	r[k] = idx;
	l[idx] = k;
	idx ++;
}
//那么第k的左边插入就是 add(l[k], x); 

//删除第k个插入
void remove(int k)
{
	r[l[k]] = r[k];
	l[r[k]] = l[k]; 
}

int main()
{
	int m;
	cin >> m;
	
	init();
	
	while(m -- )
	{
		string op;
		int k, x;
		cin >> op;
		
		if(op == "L")
		{
			cin >> x;
			add(0, x);
		}
		
		else if(op == "R")
		{
			cin >> x;
			add(l[1] , x);
		}
		
		else if(op == "D")
		{
			cin >> k;
			remove(k + 1);//因为元素下标从2开始，默认有一个单位的偏移量 
		}
		
		else if(op == "IL")
		{
			cin >> k >> x;
			add(l[k + 1], x);
		}
		
		else if(op == "IR")
		{
			cin >> k >> x;
			add(k + 1, x);
		}
	}
	
	//0代表头结点，1代表尾结点 
	for(int i = r[0]; i != 1; i = r[i])
	{
		cout << e[i] << " ";
	}
	puts("");	
	
	return 0;
}
