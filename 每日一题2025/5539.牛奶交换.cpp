#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 200005 * 2;
LL w[N];
int n, m;
char str[N];

int main()
{
	cin >> n >> m >> str;
 
	LL res = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> w[i];
		res += w[i];
		w[i + n] = w[i];//�ƻ����� 
		str[i + n] = str[i];
 	}
 	
 	int k = 0;//�ҵ�һ����һ����λ��,Ҳ���������λ��
 	while(k < n && str[k] == str[k + 1])  k++;
 	
	if(k < n)
	{
		for(int i = k + 1; i <= n; i++)
		{
			int j = i;//˫ָ��
			LL sum = 0;
			while(j <= k + n && str[i] == str[j])
			{
				sum += w[j];
				j++;
			}
			
			if(str[i] == 'R') sum -= w[j - 1];//�������ң���ȥ���һ��
			if(str[i] == 'L') sum -= w[i];//���󣬼�ȥ��һ�� 

			//!!!!ע�⣬һ�η�Χ��ʧ��ţ���ǲ��ᳬ��m�� 
			res -= min(sum, (LL)m);//����ʣ���ţ�� 
			i = j - 1;//����ָ�� 
		}
	}
	
	cout << res << endl;
		
	return 0;
}
