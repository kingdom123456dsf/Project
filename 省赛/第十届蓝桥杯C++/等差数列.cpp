#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

const int N = 100010;
int a[N];
vector<int> da;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	
	sort(a + 1, a + n + 1);
	
	int cha = 1e9;//找到最小公差 
	for(int i = 2; i <= n; i ++ )
	{
		da.push_back(a[i] - a[i - 1]);
		cha = min(cha, a[i] - a[i - 1]);
	}
	
	sort(da.begin(), da.end());//这里可以优化 
	for(int i = 0; i < da.size(); i ++ )
	{
		if(da[i] == cha) da[i] = -1e9;
	}
	
	int res = 0;
	for(int i = 0; i < da.size(); i ++ )
	{
		if(da[i] < 0) continue;
//		cout << da[i] << endl;
		res += da[i] / cha - 1;
	}
	
	printf("%d", res + n);
	
	return 0;
}
