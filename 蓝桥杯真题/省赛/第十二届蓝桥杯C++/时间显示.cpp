#include<iostream>

using namespace std;

typedef long long LL;

int main()
{
	// 24 * 60 * 60һ������� 86400
	//ע����Ŀ�����Ǻ����������Ի��ó���1000 ,86400000
	LL time;
	scanf("%lld", &time);
	time %= (24 * 60 * 60 * 1000);//�õ�һ���ڵĺ�����
	
	LL h = time / (60 * 60 * 1000);//ʱ
	time %= (60 * 60 * 1000);//һ�����ĺ�����
 	
	LL m =  time / (60 * 1000);//��
 	time %= (60 * 1000);
 	
	 LL s = time / 1000;//�� 
	  
	printf("%02lld:%02lld:%02lld", h, m, s);
	
	return 0;
}
