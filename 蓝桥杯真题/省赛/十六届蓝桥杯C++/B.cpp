#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 10;//һ����9���±��1��ʼ

int n;
int state[N];//��ʾ��ǰ״̬,0û��1~n��ʾ�����ĸ���
bool used[N];//�ж�ÿ������û���ù�(true�ù�������֮)

void dfs(int u) {
	if(u > n) {//�߽�
		bool flag = false; 
 		for(int i = 1; i <= n; i ++ )
 		{
 			for(int j = 1; j <= n; j ++ )
 			{
 				if(state[i] * state[j] > i * j + n) flag = true;
			}
		}
		
		if(!flag)
		{
			for (int i = 1; i <= n; i++) printf("%d ", state[i]);//��ӡ����
			puts("");
		}

		return;
	}

	//ö��ÿ����֧������ǰλ�ÿ�������Щ��
	for (int i = 1; i <= n; i++) {
		if (!used[i])
		{
			state[u] = i;
			used[i] = true;
			
			dfs(u + 1);
			
			state[u] = 0;
			used[i] = false;
		}
	}
}

int main() {
	cin >> n;

	dfs(1);

	return 0;

}
