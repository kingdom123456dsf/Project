#include<iostream>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7;
 
int main(){
	
	int res = 1;
	int t = 1012;
	while(t -- )
	{
		res = (res * 2) % MOD;
	}
	cout << res << endl;
	//781,448,427

	return 0;
}

