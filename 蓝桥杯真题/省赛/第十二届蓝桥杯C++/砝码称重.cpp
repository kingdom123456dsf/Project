#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int a[N];
bool st[110][N];//��¼״̬
bool f[N];//��¼ÿ�������Ĵ��Ƿ���� 
int n;

void dfs(int u, int sum)//�ڼ�������,�ʹ�
{
	if(st[u][sum]) return;//���ǵ�ǰ״̬�Ѿ����ˣ���֦
	st[u][sum] = true;
	
	f[sum] = true;//�ô𰸳��ֹ� 
	
	if(u == n) return;//ѡ���� 
	
	dfs(u + 1, sum + a[u]);//��һ�� 
	dfs(u + 1, sum);//��ѡ
	dfs(u + 1, abs(sum - a[u]));//����һ��
	//���ڴ��ڴ��Ǹ���,���ԼӾ���ֵ 
} 

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++ ) cin >> a[i];
	
	dfs(0, 0);//���� 
	
	int res = 0;
	for(int i = 1; i < N; i ++ ) if(f[i]) res ++;
	
	cout << res << endl;
	
	return 0;
}
