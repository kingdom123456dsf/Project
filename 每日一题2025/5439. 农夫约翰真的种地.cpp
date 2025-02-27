#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>//ȡ������

using namespace std;

const int N = 2e5 + 10;
int h[N], a[N], rk[N];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
		{
			int t;
			scanf("%d", &t);
			rk[t + 1] = i;//��i����������Ϊti + 1 
		}
		
		int l = 0;//��Сֵ 
		int r = 1e9;//���ֵ,��Ϊ���ֵΪ1e9,��СֵΪ1,��1������1e9�����Ҫ1e9 - 1
		for(int i = 1; i < n; i++)
		{
			int A = h[rk[i]] - h[rk[i + 1]];//hr1 - hr2
			int B = a[rk[i + 1]] - a[rk[i]];//ar2 - ar1
			
			if(B > 0) 
				r = min(r, (int)ceil((double)A / B) - 1);//x < ...(����ת��Ϊx <= ��ȡ�� - 1)
			else if(B < 0) 
				l = max(l, (int)floor((double)A / B) + 1);//x > ...(����ת��Ϊx >= ��ȡ�� + 1)
			else if(A <= 0)
			{
				r = -1;//�޽� 
				break;
			}
		}
		
		if(l > r) l = -1;//��Ϊ��ȡ��С��x,����������l 
		printf("%d\n", l);
	}
	
	return 0;
} 
