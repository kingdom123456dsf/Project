#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while(t -- )
	{
		int n, s;
		cin >> n >> s;
		
		int num = 0, sum = 0;
		for(int i = 0; i < n; i ++ )
		{
			int r, c;
			cin >> r >> c;
			
			sum += c;
			if(r == 1) num ++ ;
		}
		
		if(num >= (n + 1) / 2) cout << 1 << " " ;//注意上取整
		else cout << 0 << " ";
		
		if(sum >= s + 50) cout << 1 << endl;
		else cout << 0 << endl;
	}
	
	
	return 0;
}
