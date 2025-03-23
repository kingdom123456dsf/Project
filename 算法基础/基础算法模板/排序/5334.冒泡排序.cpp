#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N];
int n;

void bull_sort(int x[])
{
    for(int i = 0; i < n - 1; i ++ )//决定进行几次排序
    {
        bool flag = false;//优化
        for(int j = 0; j < n - i - 1; j ++ )//每次外层循环都是确定当前循环的最后一位(最大)
        {
            if(x[j] > x[j + 1])
            {
                swap(x[j], x[j + 1]);
                flag = true;//记录是否交换过
            }
        }
        if(!flag) //若是没有交换过，代表当前已经排好序了，结束即可
            break;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    
    bull_sort(a);
    
    for (int i = 0; i < n; i ++ ) cout <<a[i] << " ";
    
    return 0;
}
