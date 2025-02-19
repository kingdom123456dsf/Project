#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;
int f[N][N];//代表价值 
int v[N],w[N];
int n,vt;

//二维数组，朴素写法 
int main(){
	cin >> n >> vt;
	for(int i = 1;i <= n;i++) cin >> v[i] >> w[i];
	
	for(int i = 1;i <= n;i++)//代表第几个物品 
		for(int j = 0;j <= vt;j++)//代表当前总体积 
		{
			f[i][j] = f[i - 1][j];//不选第i个
			if(j >= v[i])
		 		f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);	
		}
		
	cout << f[n][vt] << endl;
	
	
	return 0;
}

//一维数组，优化空间写法 
 /*cin >> n >> vt;
    for(int i = 1;i <= n;i++) cin >> v[i] >> w[i];

    for(int i = 1;i <= n;i++)//代表第几个物品 
        for(int j = vt;j >= v[i];j--)//代表当前总体积 
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);   
        }

    cout << f[vt] << endl; */

