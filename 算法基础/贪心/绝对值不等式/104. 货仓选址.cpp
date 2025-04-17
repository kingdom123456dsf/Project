#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int a[N];

int main()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	int x = 0;
	if(n % 2)//Ææ
	{
		x = a[n / 2 + 1];
	} 
	else x = a[n / 2];
	
	int res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		res += abs(a[i] - x);
	}
	cout << res << endl;
 	
	return 0;
}
