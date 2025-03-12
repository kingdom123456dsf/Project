#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N], tmp[N];
int n;

void merge_sort(int q[], int l, int r)
{
	if(l >= r) return;//����ֻ��һ�����ˣ�return
	
	int mid = l + r >> 1;//�ҵ��е� 
	
	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);//�ݹ���������
	
	//�鲢(�϶�Ϊһ)
	int k = 0, i = l, j = mid + 1;//����������˵��ָ�� 
	while(i <= mid && j <= r)//δ�����������߽߱緶Χ 
		if(q[i] <= q[j]) tmp[k ++] = q[i ++];//Ĭ��Ҫ��������ȣ��ȴ������� 
		else tmp[k ++] = q[j ++];
	while(i <= mid) tmp[k ++] = q[i ++];//����һ��ָ�뵽ͷ������һ�߰�˳�����
	while(j <= r) tmp[k ++] = q[j ++];
	
	for(int i = l, k = 0; i <= r; i++, k++) q[i] = tmp[k];//���ԭ���� 
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)scanf("%d", &q[i]);
	
	merge_sort(q, 0, n - 1);
	
	for(int i = 0; i < n; i++) printf("%d ", q[i]); 
	
	return 0;
}
