#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N];
int n;

void quick_sort(int q[], int l, int r)
{
	if(l >= r) return;//�߽�����(д��l == rҲ����)
	
	int x = q[l + r >> 1];//������l, l + r >> 1, r//������Ҫע������ݹ����ѭ������ 
	int i = l - 1, j = r + 1;//������Ϊÿ�ζ������м���1��������������Ӧ�ö���һ��λ�ã��Ա���߽�����
 	while(i < j)
 	{
 		do i ++; while(q[i] < x);
 		do j --; while(q[j] > x);
 		//��һֱ���м���ֱ������������������ 
 		if(i < j) swap(q[i], q[j]);
	}
	
	quick_sort(q, l, j);//�ݹ�������������� 
	quick_sort(q, j + 1, r);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &q[i]);//����
	
	quick_sort(q, 0, n - 1);
	
	for(int i = 0; i < n; i++) printf("%d ", q[i]); 
	
	return 0;
}
