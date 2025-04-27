#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 10;//一共到9，下标从1开始

int n;
int state[N];//表示当前状态,0没，1~n表示放了哪个数
bool used[N];//判断每个数有没有用过(true用过，否则反之)

void dfs(int u) {
	if(u > n) {//边界
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
			for (int i = 1; i <= n; i++) printf("%d ", state[i]);//打印方案
			puts("");
		}

		return;
	}

	//枚举每个分支，即当前位置可以填哪些数
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
