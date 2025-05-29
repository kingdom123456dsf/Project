#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010;
int h[N], cnt;//����ģ��ѣ� �ͼ�¼����Ԫ��
int ph[N], hp[N];//����ӳ��ѣ� ��ӳ������
//ph(point->heap)���Ի�õڼ��������Ԫ�������ڶѵ��ĸ�λ��
//hp(heap->point)���Ի���ڶѵĵ�n��Ԫ�ش���ǵڼ��������Ԫ��

void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int u)
{
	int t = u;//��¼��С�±�
	if(u * 2 <= cnt && h[t] > h[u * 2]) t = u * 2;//����� 
	if(u * 2 + 1 <= cnt && h[t] > h[u * 2 + 1]) t = u * 2 + 1;//�Ҷ���
	
	if(u != t)
	{
		heap_swap(u, t);
		down(t);//�ݹ� 
 	} 
} 

void up(int u)
{
	while(u / 2 > 0 && h[u] < h[u / 2])//���Ǹ��ڵ������ 
	{
		heap_swap(u, u / 2);
		u /= 2;
	}
}

int main()
{
	int n;
	cin >> n;
	
	int m = 0;//��¼������ 
	while(n -- )
	{
		string op;
		int k, x;
		cin >> op;
		
		if(op == "I")
		{
			cin >> x;
			h[++ cnt] = x;
			m ++ ;
			ph[m] = cnt;
			hp[cnt] = m;
			up(cnt);//��Ϊû������������� 
		}
		else if(op == "PM") cout <<h[1] << endl;
		else if(op == "DM")
		{
			heap_swap(1, cnt);
			cnt -- ;
			down(1);//��Ϊ�ڶѶ��� 
		}
		else if(op == "D")//ɾ����k��������� 
		{
			cin >> k;
			k = ph[k];
			heap_swap(k, cnt);
			cnt -- ;
			up(k), down(k);
		}
		else//�޸ĵ�k��������� 
		{
			cin >> k >> x;
			k = ph[k];
			h[k] = x;
			up(k), down(k);
		}
	}
	
	return 0;
}
