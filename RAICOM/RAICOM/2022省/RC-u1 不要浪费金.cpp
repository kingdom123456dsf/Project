#include<iostream>
#include<algorithm> 

using namespace std;

const int N = 1010;
int a[N];

int n, m;

int main()
{
 	cin >> n >> m;
 	for(int i = 1; i <= n; i ++ ) cin >> a[i];
 	
 	int sum = 0, res = 0;
 	for(int i = 1; i <= n; i ++ )
 	{
 		if(sum + a[i] > m)
 		{
 			res ++ ;
 			sum = 0;
 			sum += a[i];
		}
		else sum += a[i];
 	}
 	
 	cout << res << endl;

	return 0;
}

