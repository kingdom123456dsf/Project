#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 200010;
int c[N], t[N], cnt[N];
int n, q;

int main()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> t[i];
	
	for(int i = 1; i <= n; i++) cnt[i] = c[i] - t[i];
	sort(cnt + 1, cnt + n + 1);
	
//	int l = 0;
//	while(cnt[l] == 0) l ++;
	
//	for(int i = 1; i <= n; i++) cout << cnt[i] << " ";
	
	while(q--)
	{
		int v, s = 0;
		cin >> v >> s;//s起床,v个农场
		  
		int l = 1, r = n + 1;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(cnt[mid] > s) r = mid;
			else l = mid + 1;
		}
		
		int res = n - l + 1;
		
		if(res >= v) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	return 0;
}
