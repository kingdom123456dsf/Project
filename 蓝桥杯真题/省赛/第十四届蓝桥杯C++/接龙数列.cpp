#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int g[20];//��¼ÿ���������˶��ٴΣ�(��ʵ�ʹ�����β),��Ϊ���0 ~ 9��ʮ���������Ƕ࿪��λ��ֹ����Խ��
int f[N], l[N], r[N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i ++ )
    {
        string s;
        cin >> s;
        l[i] = s[0] - '0', r[i] = s.back() - '0';//!!!ǧ��������ַ���ת����Ҫ-'0'
    }
    
    int res = 0;
    for(int i = 0; i < n; i ++ )//�죬�ں�ͷ
    {
        f[i] = 1;//�ʼ����������
        //���ڵ�i�����ֵ���λΪl[i],��ôֻ������l[i]Ϊ��β������
 		f[i] = max(f[i], g[l[i]] + 1);
 		g[r[i]] = max(g[r[i]], f[i]);
        res = max(res, f[i]);
    }
    
    cout << n - res << endl;
    
    return 0;
}
