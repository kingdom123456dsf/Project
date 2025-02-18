#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 20010;
char s[N];
int cnt[26][26];//������¼abb���͵ĳ��ִ��� 
bool check[26][26];//�ж��Ƿ��������� 
int n,f;

void update(int l, int r, int v)
{
	l = max(0, l), r = min(r , n - 1);//��ֹ����Խ��
	for(int i = l;i + 2 <= r;i++)
	{
		if(s[i] != s[i + 1] && s[i + 1] == s[i + 2])
		{
			cnt[s[i]][s[i + 1]] += v;
			if(cnt[s[i]][s[i + 1]] >= f) check[s[i]][s[i + 1]] = true;
		}
	} 
}

int main(){
	scanf("%d%d%s", &n, &f, s);
	for(int i = 0;i < n;i++) s[i] -= 'a';//ת����int,��ǰ��ĸ��ȥ'a'��ASCII��
	
 	update(0, n, 1);//��¼��ʼ��� 
 	for(int i = 0;i < n;i++)
 	{
 		char t = s[i];
 		update(i - 2, i + 2, -1);//��ȥ�ı䵱ǰ�ַ���Ӱ��������Ӵ� 
 		for(int j = 0;j < 26;j++)
 		{
			if(j != t) 
			{
				s[i] = j;
				update(i - 2, i + 2, 1);//��¼�ı������ 
				update(i - 2, i + 2, -1);//�ָ��ֳ� 
			}
 		}
 		s[i] = t;
		update(i - 2, i + 2, 1); //�ָ��ֳ�  		
	}
	
	int res = 0;
	for(int i = 0; i < 26;i++)
		for(int j = 0;j < 26;j++)
			if(check[i][j]) res++;
		
	printf("%d\n", res);	
	
	for(int i = 0;i < 26;i++)//����a 
		for(int j =0;j < 26;j++)//����b 
			if(check[i][j])	printf("%c%c%c\n", i + 'a', j + 'a', j + 'a');//�ָ��ַ���� 
		
	return 0;
}
