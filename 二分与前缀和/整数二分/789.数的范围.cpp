#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010;

int q[N];
int n, m, x;

int main() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);

        int l = 0, r = n - 1;//区间的左右端点
        while (l < r) {
            int mid = l + r >> 1;//右移1,相当于除2，好处是加法优先级更高不用写括号
            //说明分界点在x右边
            if (q[mid] >= x) r = mid;
            else l = mid + 1;
        }

        if (q[r] == x) {
            cout << r << " ";

            r = n - 1;//右端点
            while (l < r) {
                int mid = l + r + 1 >> 1;//因为是l= ，所以要加一
                if (q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
        else cout << "-1 -1" << endl;
    }

    return 0;
}
