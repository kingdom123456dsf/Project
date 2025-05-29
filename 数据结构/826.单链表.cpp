#include<iostream>

using namespace std;

const int N = 100010;
//e[]��ʾ��ǰ�ڵ��ֵ
//ne[]��ʾ��ǰ�ڵ�ָ��Ľڵ��ֵ��nextָ���Ƕ��٣� 
//head��ʾͷ�����±� 
//idx��ʾ�Ѿ��õ����ĸ��� 
int e[N], ne[N], head, idx;

//��ʼ�� 
void init()
{
	head = -1;
	idx = 0;//��һ�������0 
}

//��x���뵽ͷ��� 
void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx ++;
}

//��x���뵽��k���֮�� 
void add(int k, int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx ++;
}

//��k�������һ����ɾ�� 
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
