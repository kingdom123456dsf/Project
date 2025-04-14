#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e6 + 10;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int len = s1.size();
	
	int l = 0, r = 0;//�ҵ����ȳ��ֺ������ֵ�λ�� 
	for(int i = 0; i < len; i ++ )
	{
		if(s1[i] == '#' || s2[i] == '#')
		{
			l = min(l, i);
			r = max(r, i);
		}
	}
	
	int res = 0;
	for(int i = l; i < r; i ++ )
	{
		//��һ�����
		//# .
		//. ? 
		if(s1[i] == '#' && s1[i + 1] == '.' && s2[i] == '.')
		{
			res ++;
			s1[i + 1] = '#';
		}
		//�ڶ������
		//. ?
		//# . 
		if(s2[i] == '#' && s2[i + 1] == '.' && s1[i] == '.')
		{
			res ++;
			s2[i + 1] = '#';
		}
		//���������,��Ҫ�ٴ��ҵ���һ�����ֵĹܵ�λ�� 
		//��һ���ȳ��ֹܵ����͸���һ�е���һ��λ�ñ�ɹܵ� 
		//# .
		//# . 
		if(s1[i] == '#' && s2[i] == '#' && s1[i + 1] == '.' && s2[i + 1] == '.')
		{
			int x1 = 0, x2 = 0;//�ҵ���һ�����ֵĹܵ�λ�� 
			for(int j = i + 1; j <= r; j ++ )
			{
				if(s1[j] == '#')
				{
					x1 = j;
					break;
				}
				if(s2[j] == '#')
				{
					x2 = j;
					break;
				}
			}
			if(x1 >= x2)//��һ���ȳ��� 
			{
				res ++;
				s1[i + 1] = '#';
			}
			else
			{
				res ++;
				s2[i + 1] = '#';
			}
		}
		
	}
	cout << res << endl;
	
	return 0;
}
