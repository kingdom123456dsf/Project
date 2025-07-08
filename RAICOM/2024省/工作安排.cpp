#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 5010;

struct work{
    int t, d, p;
}w[N];

bool cmp(work a, work b)
{
    if(a.p != b.p) return a.p > b.p;
    else return a.d < b.d;
}

int main()
{
    int T;
    cin >> T;
    
    while(T -- )
    {
    	int n;  // 工作数量
        cin >> n;
        for(int i = 0; i < n; i ++ )
        {
            int t, d, p;
            cin >> t >> d >> p;
            w[i] = {t, d, p};
        }
        
        // 按照截止时间排序
        sort(w, w + n, cmp);
        
		int res = 0;  // 最大报酬
		int time = 0;
        for(int i = 0; i < n; i ++ )
        {
        	if(time + w[i].t <= w[i].d)
        	{
        		res += w[i].p;
        		time += w[i].t;
			}
		}

        cout << res << endl;
    }
    
    return 0;
}
