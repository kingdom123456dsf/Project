#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010, M = 2 * N;
bool st[N];//���ڼ�¼ÿ�����Ƿ��߹� 
int h[N], e[M], ne[M], idx;//�͵������Ψһ������ǿ���N�������� 
int n;
int ans = N;//�� 

void add(int a, int b)//a���b������ 
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++ ;
}

//�����ɾȥ��ǰ���������ͨ���е�ĸ��� 
int dfs(int u)
{
	st[u] = true;//��ǵ�ǰ���߹��� 
	
	int sum = 1;//��¼�������,��ǰ��һ���� 
	int res = 0;//��¼ɾȥ��ǰ�����ͨ��..... 
	//�뵥�������һ�� 
	for(int i = h[u]; i != -1; i = ne[i])//ֻ���������Ǳ�����ǰ��ĵ�����
	{
		int j = e[i];//�����ľ��ǵ� 
		if(!st[j])
		{
			int s = dfs(j);
			res = max(res, s);//ȡɾȥ��ǰ��������� 
			sum += s; 
		}
	} 
	res = max(res, n - sum);//��ǰ�����ϵ���ͨ��ĵ���������͵�ǰ��֮�µ���� 
	
	ans = min(res, ans);//�������������������У�ȡ��С 
	return sum;	
}

int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n;
	
	for(int i = 0; i < n - 1; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	
	dfs(1);//������ 
	
	cout << ans << endl;
	
	return 0;
}
