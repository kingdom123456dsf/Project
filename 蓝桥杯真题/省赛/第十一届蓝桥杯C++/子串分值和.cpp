#include<iostream>
#include<cstring>

using namespace std;

typedef long long LL;

//��һ�γ��ֵ�λ��,�����A ~ z��ASCII�� 
int last[200];

int main()
{
	string s;
	cin >> s;
	
	int n = s.size();//ע��n��λ�� 
	s = ' ' + s;//�������±��1~n 
	
	LL res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		//��ǰԪ�ص���һ����ͬԪ�غ�һλ�ĸ��� �� ��ǰԪ�غ��ȡ����ĸ��� 
		res += (LL)(i - last[s[i]]) * (n - i + 1);//��LL��ֹ���㱬int
		last[s[i]] = i;//����Ԫ�ص�λ�� 
	}
	
	cout << res << endl;
	
	return 0;
}
