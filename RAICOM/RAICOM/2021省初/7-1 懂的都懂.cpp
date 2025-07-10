#include<iostream>
#include<algorithm>

using namespace std;

const int N = 55;
bool st[55 * 255];
int a[N];

int main()
{
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	
	for(int i = 1; i <= n; i ++ )
		for(int j = i + 1; j <= n; j ++ )
			for(int g = j + 1; g <= n; g ++ )
				for(int h = g + 1; h <= n; h ++ )
				{
					int num = a[i] + a[j] + a[g] + a[h];
				 	st[num] = true;
				}
		
	while(k -- )
	{
		int m;
		cin >> m;
		
		bool flag = true;
		while(m -- )
		{
			int x;
			cin >> x;
			if(!st[x * 4])
			{
				flag = false;
			}
		}
		
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	
	return 0;
}
