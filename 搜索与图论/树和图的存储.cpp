#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], idx;//和单链表的唯一区别就是开了N个单链表 

void add(int a, int b)//a点和b点相连 
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++ ;
}

int main()
{
	memset(h, -1, sizeof h);
	
	return 0;
}
