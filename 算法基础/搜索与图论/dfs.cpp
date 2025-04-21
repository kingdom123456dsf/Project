#include<iostream>

using namespace std;

int mem[20];

int dfs(int x)
{
	if(mem[x]) return mem[x];
	
	int sum = 0;
	if(x == 1) sum = 1;
	else if(x == 2) sum = 2;
	else if(x == 3) sum = 4;//1+1+1;1+2;2+1;3
 	else sum = dfs(x - 3) + dfs(x - 2) + dfs(x - 1);
 	
 	mem[x] = sum;
 	return sum;
}
//4可以由1,2,3走来 

int main()
{
	int n;
	cin >> n;
	
	cout << dfs(n);
		
	return 0;
}
