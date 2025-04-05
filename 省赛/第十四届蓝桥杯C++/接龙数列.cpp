#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int g[20];//记录每个数出现了多少次，(其实就代表首尾),因为最多0 ~ 9这十个数，但是多开几位防止数组越界
int f[N], l[N], r[N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i ++ )
    {
        string s;
        cin >> s;
        l[i] = s[0] - '0', r[i] = s.back() - '0';//!!!千万别忘了字符型转整形要-'0'
    }
    
    int res = 0;
    for(int i = 0; i < n; i ++ )//快，在后，头
    {
        f[i] = 1;//最开始都是它本身
        //由于第i个数字的首位为l[i],那么只关心以l[i]为结尾的数字
 		f[i] = max(f[i], g[l[i]] + 1);
 		g[r[i]] = max(g[r[i]], f[i]);
        res = max(res, f[i]);
    }
    
    cout << n - res << endl;
    
    return 0;
}
