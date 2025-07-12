#include<iostream>

using namespace std;

const int N = 20;
int s[] = {0, 12, 9, 7, 5, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
int ans[N];

int main() 
{
	int n;
	cin >> n;
	
	while(n -- )
	{
		for(int i = 1; i <= 20; i ++ )
		{
			int p, k;
			cin >> p >> k;
			ans[i] += s[p] + k;
		}
	}
	
	for(int i = 1; i <= 20; i ++ )
	{
		cout << i << " " << ans[i] << endl;
	}
	
	return 0;
}
