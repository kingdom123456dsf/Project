#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int last[N], score[N];//��¼��һ���ж�����ʱ�̣���¼���ȼ� 
bool st[N];//��¼�Ƿ��������

PII order[N];
int n, m, T;

int main()
{
 	scanf("%d%d%d", &n, &m, &T);
	 
	for(int i = 0; i < m; i++) scanf("%d%d", &order[i].x, &order[i].y);//����
 	sort(order, order + m);//����,pair�������Ȱ��յ�һ���Ƚ�,��һ��������ͬ���յڶ����Ƚ�
 
 	//ö��ÿ������
	for(int i = 0; i < m; )
	{
		int j = i;
		while(j < m && order[i] == order[j]) j ++;//�����ж�ͬһʱ��ͬһ����ظ���� 
		int t = order[i].x, id = order[i].y, cnt = j - i; //��¼�������� 
		i = j;
		
		score[id] -= t - last[id] - 1;//��tʱ��֮ǰ��(������t)
		if(score[id] < 0) score[id] = 0;
		if(score[id] <= 3) st[id] = false;
		
	 	score[id] += cnt * 2;//tʱ��
		if(score[id] > 5) st[id] = true; 
		
		last[id] = t; 		
	}
	
	for(int i = 1; i <= n; i++)//ö��ÿ�ҵ꣬�鿴�Ƿ���Tʱ��֮���޶�����
	{
		if(last[i] < T)//��Ϊ����T(0 ~ T - 1) 
		{
			score[i] -= T - last[i];
			if(score[i] <= 3) st[i] = false;
		}
	} 
	
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		res += st[i];
	}
	
	printf("%d", res);
	
	return 0;
}
