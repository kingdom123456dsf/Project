#include<iostream>
#include<cstdio>

using namespace std;

const int N = 20;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];//�У����Խ��ߣ�б�Խ���
int n;

void dfs(int x, int y, int s)
{
	if(y == n) y = 0, x ++;//��ǰ�е����ߵ�ͷ��,��������һ�еĵ�һλ
	
	if(x == n)//��������
	{
	    if(s == n)//�ʺ�Ҳ������
	    {
	        for(int i = 0; i < n; i ++ ) puts(g[i]);
	        puts("");
	    }
	}
	
	dfs(x, y + 1, s);//��ǰ���Ӳ��Żʺ�,ֱ��ȥ��ǰ�е���һ��
	
	for(int i = 0; i < n; i ++ )
	{
	    if(!row[i] && !col[i] && !dg[x + y] && !udg[n + x - y])//��������
	    {
	        g[x][y] = 'Q';
	        row[i] = col[i] = dg[x + y] = udg[n + x - y] = true;
	        dfs(x, y + 1, s + 1);
	        //�ָ��ֳ�
	        row[i] = col[i] = dg[x + y] = udg[n + x - y] = false;
	        g[x][y] = '.';
	    }
	}
}

int main()
{
	
	cin >> n;
	for(int i = 0; i < n; i ++ )
		for(int j = 0; j < n; j ++ )
			g[i][j] = '.';//��ʼ�� 
		
	dfs(0, 0, 0); 
	
	return 0;
} 
