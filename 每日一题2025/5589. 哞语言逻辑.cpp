#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 200010;
int q[N], id[N], l[N], r[N], cnt;//id记录当前在第几段,l、r记录当前段的左右边界 
int ones[N], zeroes[N];
int n, m;

int main()
{
	char str[10];
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		if(!strcmp(str, "true") || !strcmp(str, "or")) q[i] = 1;//true和or为1 
		if(i & 1)//奇数
		{
			if(i == 1 || q[i - 1] == 1)//and段的段首 
			{
				cnt ++;
				l[cnt] = i, r[cnt - 1] = i - 2;//当前段的左边界和上一段的右边界
			 	if(cnt >= 2) ones[cnt - 1] = ones[cnt - 2] + !zeroes[i - 2];
			 	zeroes[i] = !q[i];//段内 
			}
			//在段中 
			else zeroes[i] = zeroes[i - 2] + !q[i];
			id[i] = cnt;//当前的布尔值在第几段 
		} 
	}
	r[cnt] = n;//最后一段的右边界
	ones[cnt] = ones[cnt - 1] + !zeroes[n];//最后一段后面没有或，所以需要自己维护一下
	
	while(m --)
	{
		int left, right;
		scanf("%d%d%s", &left, &right, &str);
		bool res = !strcmp(str, "true");//期望的结果
		
		int lid = id[left],  rid = id[right];//left、right在哪一段
		int a = ones[lid - 1] + ones[cnt] - ones[rid]; //1,2
		
		int b = zeroes[r[rid]] - zeroes[right];//3,4段，先判断右边
		if(l[lid] != left) b += zeroes[left - 2];
		
		if(res == (a || !b && true) || res == (a || !b && false)) printf("Y");
		else printf("N");		
	}
	
	return 0;
}
