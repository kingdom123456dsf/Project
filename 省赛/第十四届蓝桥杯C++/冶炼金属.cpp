#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10010;
int a[N], b[N];
int n;

int is_valid(int x)
{
	for(int i = 0; i < n; i ++ )
	{
		if(a[i] / x > b[i]) return 2;//答案小了,l 
		if(a[i] / x < b[i]) return 3;//答案大了,r 
	}
	return 1;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++ ) cin >> a[i] >> b[i];
	
	int l = 1, r = 1e9;
	while(l < r)
	{
		int mid = l + r >> 1;
		int t = is_valid(mid);
		if(t == 1 || t == 3) r = mid;
		else l = mid + 1;
	}
	cout << l << " ";
	
	l = 1, r = 1e9;
	while(l < r)
	{
		int mid = l + r + 1 >> 1;
		int t = is_valid(mid);
		if(t == 1 || t == 2) l = mid;
		else r = mid - 1;
	}
	cout << r;
	
	return 0;
}
