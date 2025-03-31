#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> A;

void mul(vector<int> &A, int x)
{
	int t = 0;
	for(int i = 0; i < A.size(); i ++ )
	{
		t += A[i] * x;
		A[i] = t % 10;
		t /= 10;
	}
	if(t) A.push_back(t);
	while(A.size() > 1 && A.back() == 0) A.pop_back();//去除前导0 
}

void add(vector<int> &A, int pos)
{
	int t = 1;//！！！进位 
	for(int i = pos; i < A.size(); i ++ )
	{
		t += A[i];
		A[i] = t % 10;
		t /= 10;
	}
	if(t) A.push_back(t);
}

int main()
{
	int n;
	string s;
	cin >> n >> s;
	
	reverse(s.begin(), s.end());//倒序
	
	int pos = s.find('.');
	for(int i = 0; i < s.size(); i ++ )
	{
		if(s[i] != '.') A.push_back(s[i] - '0');
	} 
	
	while(n --) mul(A, 2);
	
	if(A[pos - 1] >= 5) add(A, pos);//四舍五入，进位 
	
	for(int i = A.size() - 1; i >= pos; i -- ) cout << A[i];
	
	return 0;
}
