#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int N = 300010;
vector<int> ans;
int n;
char s[N];

int main()
{
 	scanf("%d%s", &n, s);
 	
 	int r = n;//�����䳤������Ϊn 
 	for(int i = 0; i < n; i++)
 	{
 		if(s[i] == '0') continue;//��û����Ⱦ
		int j = i + 1;
		while(j < n && s[j] == '1') j++;//˫ָ�� 
		//Ĭ��cλ���м� 
		int c = j - i;//�����䳤��
		int d = (c - 1) / 2 ;//2d + 1 = c
		//cλ������ 
		if(!i || j == n) d = c - 1;
		r = min(r, d);//�õ���������(ľͰԭ��ֻ��ȡ��̵���һ��)
		ans.push_back(c); 
		
		i = j;//������ע��ֱ�Ӵӵ�ǰ��������ұ߿�ʼ����(�ұߵ�һ��Ϊ0) 
	}
	
	int res = 0;
	for(auto c : ans)
	{
		//c��2r+1����ȡ�� 
		res += (c + 2 * r + 1 - 1) / (2 * r + 1);
	}
	
	printf("%d", res);
	
	return 0;
}
