#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 1010;
int cnt[N];

int main()
{
	string s;
	cin >> s;
	
	bool flag = true;//�����ǼӺŻ��Ǽ��� 
	int Max = 0, Min = 0;//�����С��� 
	for(int i = 0; i < s.size(); i ++ )
	{
		int x = 0, y = 0;//x�ǳ�����dyǰ��ϵ�� 
	 	while(i < s.size() && s[i] != 'd' && s[i] != '+' && s[i] != '-')//��Ϊ�����ܲ�ֹһλ 
	 	{
			x = x * 10 + (s[i ++ ] - '0');	
		}
		
		if(s[i] == 'd')//֤��ǰ����ϵ�� 
		{	
			i ++ ;//����һλ 
			
			while(i < s.size() && s[i] != '+' && s[i] != '-')//�õ�y 
			{
				y = y * 10 + (s[i ++ ] - '0');
			}
			
			//��¼ 
			if(x) cnt[y] += x;
			else//û��ϵ����ϵ��Ϊ1 
			{
				x = 1;
				cnt[y] += 1;
			}
			
			if(flag)//��
			{
				Max += x * y;
				Min += x * 1;
			} 
			else
			{
				Max -= x * 1;
				Min -= x * y;
			}
			
		}
		else//�Ӽ��ţ�֤��xֻ�ǵ����ĳ��� 
		{
			if(flag)
			{
				Max += x;
				Min += x;
			}
			else
				Max -= x;
				Min -= x;
			}
		}
		
		if(s[i] == '+') flag = true;
		else flag = false;	 	
	}
	
	for(int i = 2; i <= N; i ++ )
	{
		if(cnt[i]) cout << i << " " << cnt[i] << endl;
	}
	cout << Min << " " << Max << endl;
	
	
	return 0;
}
