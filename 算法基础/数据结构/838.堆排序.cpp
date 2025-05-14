#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int n, m;
int h[N], cnt;//h����ģ��ѵ�����

void down(int u)//�൱�ڵݹ�Ĺ��� 
{
	int t = u;//������СԪ���±�
	if(u * 2 <= cnt && h[t] > h[u * 2]) t = u * 2;//�������ӽ��
	if(u * 2 + 1 <= cnt && h[t] > h[u * 2 + 1]) t = u * 2 + 1;//���ӽ��
	
	if(t != u)//�����±꽻���� 
	{
		swap(h[t], h[u]);
		down(t);
	}  
}

int main()
{
 	cin >> n >> m;
 	for(int i = 1; i <= n; i ++ ) cin >> h[i];
 	cnt = n;
 	
 	//���Դ�n/2��ʼdown������ʱ�临�Ӷ�O(n) 
 	for(int i = n / 2; i >= 1; i -- ) down(i);//ʵ�ֶѽṹ 
	
	while(m -- )
	{
		cout << h[1] << " ";
		h[1] = h[cnt];//��βԪ�ظ�����Ԫ�� 
		cnt -- ;//ɾ��βԪ�ؿռ� 
		down(1); 
	}
	
	return 0;
} 
