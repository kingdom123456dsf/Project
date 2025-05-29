#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int e[N], l[N], r[N], idx;

void init()
{
	r[0] = 1, l[1] = 0;
	idx = 2;
}

//��k���ұ߲���x 
void add(int k, int x)
{
	e[idx] = x;
	r[idx] = r[k];
	l[r[k]] = idx;
	
	r[k] = idx;
	l[idx] = k;
	idx ++;
}
//��ô��k����߲������ add(l[k], x); 

//ɾ����k������
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
			remove(k + 1);//��ΪԪ���±��2��ʼ��Ĭ����һ����λ��ƫ���� 
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
	
	//0����ͷ��㣬1����β��� 
	for(int i = r[0]; i != 1; i = r[i])
	{
		cout << e[i] << " ";
	}
	puts("");	
	
	return 0;
}
