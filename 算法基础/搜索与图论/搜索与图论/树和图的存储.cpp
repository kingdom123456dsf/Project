#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], idx;//�͵������Ψһ������ǿ���N�������� 

void add(int a, int b)//a���b������ 
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
