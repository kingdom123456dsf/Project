#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define l first
#define r second

using namespace std;

typedef pair<int, int> PII;

int n;
vector<PII> q;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i ++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		q.push_back({l, r});
	}
	
	//��˵����� 
	sort(q.begin(), q.end());
	
	//С���ѣ��Ѷ�Ϊ��Сֵ Max_r�е���Сr 
	priority_queue<int, vector<int>, greater<int>> heap;
	for(int i = 0; i < n; i ++ )
	{
		auto t = q[i];
		if(heap.empty() || t.l <= heap.top())//Ϊ�ջ����н��㣬�¿�һ������ 
		{
			heap.push(t.r);
		}
		else//�����޽��� 
		{
			heap.pop();//�����Ҷ˵㵽��ǰ������Ҷ˵�
			heap.push(t.r); 
		}
	}
	
	printf("%d\n", heap.size());
	
	return 0;
}
