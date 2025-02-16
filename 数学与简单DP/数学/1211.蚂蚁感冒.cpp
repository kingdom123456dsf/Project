#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 55;
int x[N];

int main(){
	int n;cin >> n;
	for(int i = 0;i < n;i++) cin >> x[i];
	
	int left = 0,right = 0;
	for(int i = 1;i < n;i++)
	{
		if(abs(x[i]) > abs(x[0]) && x[i] < 0) right++;//右边向左走
		if(abs(x[i]) < abs(x[0]) && x[i] > 0) left++; //左边向右走
	}
	
	int res = 0;
	if(x[0] > 0 && right > 0 || x[0] < 0 && left > 0) res = right + left + 1;
	else res = 1;
	
	cout << res << endl;
	
	return 0;
}
