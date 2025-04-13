#include<iostream>

using namespace std;

const int MOD = 1000000007;
int ans;
int n, m;

void dfs(int u, int i, int j, int st)//�Ƶ껨 
{
	if(u == 0 && i == 0 && j == 0 && st == 1)
	{
		ans = (ans + 1) % MOD;
	}
	
	if(u < 0 || i < 0 || j < 0) return;//���Ϸ�������
	
	//�� 
 	if(i > 0) dfs(u * 2, i - 1, j, 0);
 	//�� 
 	if(u > 0 && j > 0) dfs(u - 1, i, j - 1, 1);
}

int main()
{
	cin >> n >> m;
	
	dfs(2, n, m, -2);//�ƣ��꣬����(0/1,���) 
	
	cout << ans << endl;
	
	return 0;
}
