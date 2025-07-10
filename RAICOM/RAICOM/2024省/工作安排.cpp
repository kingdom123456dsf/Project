#include GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 5010;

struct work{
    int t, d, p;
    
    bool operator<(const work &temp) const
    {
    	return d < temp.d;
	}
}w[N];

int f[N][N];//dp状态表示 

int main()
{
    int T;
    cin >> T;
    
    while(T -- )
    {
    	int n;  // 工作数量
        cin >> n;
        for(int i = 1; i <= n; i ++ )
        {
            int t, d, p;
            cin >> t >> d >> p;
            w[i] = {t, d, p};
        }
        
        //将截止时刻从大到小排序即可 
        sort(w + 1, w + 1 + n);
        
        memset(f, 0, sizeof f);

        for(int i = 1; i <= n; i ++ )
        {
        	for(int j = w[i].d; j >= w[i].t; j -- )
        	{
     		 	f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i].t] + w[i].p);
			}
		}
		
		int res = 0;
		for(int j = 1; j <= w[n].d; j ++ )
		{
			res = max(f[n][j], res);
		}
		cout << res << endl;
		
    }
    
    return 0;
}
