#include<iostream>
#include<algorithm>
#include<cstring>

typedef long long LL;

using namespace std;

const int N = 200010;
LL a[N],b[N];
LL n, m;

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++) cin >> b[i];
	
	for(int i = 1;i <= m;i++)
	{
		LL t = 0;//t����ǰ�ǵ����� 
		for(int j = 1;j <= n;j++)
		{
			if(t >= b[i]) break; //����Ѿ��������ǹ����������ǰѭ�� 
			if(a[j] > t)//����ǰţ�ܳԵ��ǹ� 
			{
				LL d = a[j];
				a[j] += min(a[j] - t, b[i] - t);
				t = d;
			}
		}
	}
		
	for(int i = 1;i <= n;i++) cout << a[i] << endl;
	
	return 0;
}
