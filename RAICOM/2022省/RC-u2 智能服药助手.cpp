#include<iostream>
#include<cstring>
#include<map>

using namespace std;

const int N = 1010;
int mp[N];
int g[N];
int n, m;

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) cin >> g[i];//安全的时间间隔 
	
	memset(mp, -2, sizeof mp);
	while(m -- )
	{
		int t, k;//时刻和服了几种药物 
		cin >> t >> k;
		for(int i = 1; i <= k; i ++ )
		{
			int x;
			cin >> x;//药物种类
			
			if(mp[x] == -1) continue;//无间隔
			 
			if(mp[x] >= 0)//若是之前服用过 
			{
				if(t - mp[x] < g[x])
				{
					cout << "Don't take " << x << " at " << t << "!" << endl;
				}
				else mp[x] = t;//x药物在t时刻服用 
			}
			else mp[x] = t;//x药物在t时刻服用 
		}
	}
	
	return 0;
}
