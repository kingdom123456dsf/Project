#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 200010;
int q[N], id[N], l[N], r[N], cnt;//id��¼��ǰ�ڵڼ���,l��r��¼��ǰ�ε����ұ߽� 
int ones[N], zeroes[N];
int n, m;

int main()
{
	char str[10];
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		if(!strcmp(str, "true") || !strcmp(str, "or")) q[i] = 1;//true��orΪ1 
		if(i & 1)//����
		{
			if(i == 1 || q[i - 1] == 1)//and�εĶ��� 
			{
				cnt ++;
				l[cnt] = i, r[cnt - 1] = i - 2;//��ǰ�ε���߽����һ�ε��ұ߽�
			 	if(cnt >= 2) ones[cnt - 1] = ones[cnt - 2] + !zeroes[i - 2];
			 	zeroes[i] = !q[i];//���� 
			}
			//�ڶ��� 
			else zeroes[i] = zeroes[i - 2] + !q[i];
			id[i] = cnt;//��ǰ�Ĳ���ֵ�ڵڼ��� 
		} 
	}
	r[cnt] = n;//���һ�ε��ұ߽�
	ones[cnt] = ones[cnt - 1] + !zeroes[n];//���һ�κ���û�л�������Ҫ�Լ�ά��һ��
	
	while(m --)
	{
		int left, right;
		scanf("%d%d%s", &left, &right, &str);
		bool res = !strcmp(str, "true");//�����Ľ��
		
		int lid = id[left],  rid = id[right];//left��right����һ��
		int a = ones[lid - 1] + ones[cnt] - ones[rid]; //1,2
		
		int b = zeroes[r[rid]] - zeroes[right];//3,4�Σ����ж��ұ�
		if(l[lid] != left) b += zeroes[left - 2];
		
		if(res == (a || !b && true) || res == (a || !b && false)) printf("Y");
		else printf("N");		
	}
	
	return 0;
}
