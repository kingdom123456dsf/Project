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
		w[i + n] = w[i];//破环成链 
		str[i + n] = str[i];
 	}
 	
 	int k = 0;//找第一个不一样的位置,也就是相向的位置
 	while(k < n && str[k] == str[k + 1])  k++;
 	
	if(k < n)
	{
		for(int i = k + 1; i <= n; i++)
		{
			int j = i;//双指针
			LL sum = 0;
			while(j <= k + n && str[i] == str[j])
			{
				sum += w[j];
				j++;
			}
			
			if(str[i] == 'R') sum -= w[j - 1];//若是向右，减去最后一个
			if(str[i] == 'L') sum -= w[i];//向左，减去第一个 

			//!!!!注意，一段范围损失的牛奶是不会超过m的 
			res -= min(sum, (LL)m);//更新剩余的牛奶 
			i = j - 1;//更新指针 
		}
	}
	
	cout << res << endl;
		
	return 0;
}
