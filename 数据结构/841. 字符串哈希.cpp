#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef unsigned long long ULL;//2 ^ 64
//����������൱�ڶ�2 ^ 64ȡģ��,�����׳�ͻ2 ^ 64 

const int N = 100010, P = 131;//P����ֵ,Ĭ��131���ݳ��ֳ�ͻ 
ULL h[N], p[N];
char str[N];
int n, m;

ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", str + 1);//�±��1��ʼ
	//��0��ʼ�Ļ��൱�ڽ�λֵ��0λ������˭ӳ�䣬ֵ����һ����
	
	p[0] = 1;
	for(int i = 1; i <= n; i ++ )//Ԥ���� 
	{
		p[i] = p[i - 1] * P;//�����λ��ǰ׺��
		h[i] = h[i - 1] * P + str[i];//P���Ƶ��� ���ټ������λ 
	} 
	
	while(m -- )
	{
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		
		if(get(l1, r1) == get(l2, r2)) puts("Yes");
		else puts("No");
	}	
	
	return 0;
}
