#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define ts first
#define id second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int cnt[N];//ͳ��ĳ��id���ֶ��ٴ� 
bool st[N];//�ж��Ƿ�>=k
PII logs[N];

int main()
{
	int n, d, k;
	scanf("%d%d%d", &n, &d, &k);
	
	for(int i = 0; i < n; i ++)
	{
		scanf("%d%d", &logs[i].ts, &logs[i].id);
	}
	sort(logs, logs + n);//����
	
	for(int i = 0, j = 0; i < n; i ++)
	{
		int id = logs[i].id;
		cnt[id] ++;//ͳ�ƴ��� 
		
		while(logs[i].ts - logs[j].ts >= d)//��������ڵ���d
		{
			cnt[logs[j].id] --;//ȥ����������� 
	 	 	j ++;
		}
		
		if(cnt[id] >= k) st[id] = true;
	}
	
	for(int i = 0; i < N; i++)
	{
		if(st[i]) cout << i << endl;
	}
	
	
	return 0;
}
