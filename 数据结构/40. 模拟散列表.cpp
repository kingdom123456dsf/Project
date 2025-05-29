#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 200003;//ֵ�������ĵ�һ������ 
const int null = 0x3f3f3f3f; 
int h[N];
int n;

int find(int x)//�ҵ�xӳ�䵽��ϣ����������
{
	int k = (x % N + N) % N;
	
	while(h[k] != null && h[k] != x)//������ѭ��(ÿһ��λ�ö�����)����Ϊ���������� 
	{
		k ++ ;
		if(k == N) k = 0;//���ǵ�ĩβ�ˣ����ͷ��ʼ 
	}
	
	return k;
} 

int main()
{
	memset(h, 0x3f, sizeof h);//��ʼ������Ϊ���Ҳû1e9�� 
	
 	scanf("%d", &n);
 	
 	while(n -- )
 	{
 		char op[2]; int x;
 		scanf("%s%d", op, &x);
 		
 		if(*op == 'I') h[find(x)] = x;
 		else 
 		{
 			if(h[find(x)] != null) puts("Yes");
 			else puts("No");
		}
 	}
	
	return 0;
}
