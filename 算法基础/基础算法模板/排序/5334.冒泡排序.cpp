#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N];
int n;

void bull_sort(int x[])
{
    for(int i = 0; i < n - 1; i ++ )//�������м�������
    {
        bool flag = false;//�Ż�
        for(int j = 0; j < n - i - 1; j ++ )//ÿ�����ѭ������ȷ����ǰѭ�������һλ(���)
        {
            if(x[j] > x[j + 1])
            {
                swap(x[j], x[j + 1]);
                flag = true;//��¼�Ƿ񽻻���
            }
        }
        if(!flag) //����û�н�����������ǰ�Ѿ��ź����ˣ���������
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
