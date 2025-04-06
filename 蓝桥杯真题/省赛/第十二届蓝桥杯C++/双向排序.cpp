#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;//O(N ^ 2)会超时，但是没办法时间不够先暴力
int a[N]; 
int n, m;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++ )
	{
		a[i] = i;
	}
	
	while(m -- )
	{
		int p, q;
		scanf("%d%d", &p, &q);
		if(p == 0)//1 ~ q降序 
		{
			sort(a + 1, a + q + 1, cmp);
		}
		else if(p == 1)//q ~ n升序 
		{
			sort(a + q, a + n + 1);
		}
		
	}
	
	for(int i = 1; i <= n; i ++ ) printf("%d ", a[i]);
	
	
	return 0;
}
