#include<iostream>

using namespace std;

const int N = 7510;
int a[N], b[N], ans[N];
int n,cnt;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	for(int i = 1;i <= n;i++) cin >> b[i];
	
	for(int i = 1;i <= n;i++)//�жϳ�ʼ����м�ͷţ��Ӧ
		if(a[i] == b[i])  cnt++;
		
	for(int i = 1;i <= n;i++)
	{
		int l = i,r = i;//������ͷţʱ���м��һ����
		int sum = cnt; 
		while(l >= 1 && r <= n)
		{
			if(l < r)
			{
   			 	if(a[l] == b[l]) sum--;
				if(a[r] == b[r]) sum--;
				if(a[l] == b[r]) sum++;
				if(a[r] == b[l]) sum++;
			}
			ans[sum]++;
			l--,r++;
		}
		
		l = i,r = i + 1;//��ż��ͷţʱ���м�������
		sum = cnt; 
		while(l >= 1 && r <= n)
		{
			if(l < r)
			{
   			 	if(a[l] == b[l]) sum--;
				if(a[r] == b[r]) sum--;
				if(a[l] == b[r]) sum++;
				if(a[r] == b[l]) sum++;
			}
			ans[sum]++;
			l--,r++;
		}
	}
		
	
	for(int i = 0;i <= n;i++) cout << ans[i] << endl;
	
	return 0;
}
