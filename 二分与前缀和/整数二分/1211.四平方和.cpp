#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;

const int N = 2500010;//因为logn，所以只需要250万即可 

struct Sum
{
	int s, c, d;
	bool operator< (const Sum &t)const//重载<运算符，按字典序较小的进行排序 
	{
		if(s != t.s) return s < t.s;
		if(c != t.c) return c < t.c;
		return d < t.d;
	}
}sum[N];//Sum结构体类型的sum数组 

int n, m;


int main(){
    
    cin >> n;
    
    for(int c = 0; c * c <= n; c++)
    	for(int d = c; c * c + d * d <= n; d++)
    		sum[m++] = {c * c + d * d, c, d};
    		
    sort(sum,sum + m);//按字典序进行比较,排序
    
    for(int a = 0; a * a <= n;a++)
    	for(int b = a; b * b + a * a <= n;b++)
		{
    		int t = n - a * a - b * b;
    		int l = 0, r = m;
    		while(l < r)
			{
    			int mid = l + r >> 1;
    			if(sum[mid].s >= t) r = mid;
    			else l = mid + 1;
			}
			
			if(sum[l].s == t){
				printf("%d %d %d %d", a, b, sum[l].c, sum[l].d);
				return 0;
			}			
			
		}
    
    
}
