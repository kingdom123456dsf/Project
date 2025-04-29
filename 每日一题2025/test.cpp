#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 100010;
int a[N];

int main()
{
 	int n, q;
 	cin >> n >> q;
 	for(int i = 1; i <= n; i ++ ) cin >> a[i];
 	
 	while(q -- )
 	{
 		int k;
 		cin >> k;
 		
 		int l = 1, r = n + 1;
 		while(l < r)
 		{
 			int mid = l + r >> 1;
 			if(a[mid] >= k) r = mid;
 			else l = mid + 1;
		}
		
		if(a[l] == k)
		{
			cout << l - 1 << " ";
			r = n;
			while(l < r)
			{
				int mid = l + r + 1 >> 1;
				if(a[mid] <= k) l = mid;
				else r = mid - 1;
	 		}
	 		cout << r - 1 << endl;
		}
		else cout << -1 << " " << -1 << endl; 
	}
	
	return 0;
}
