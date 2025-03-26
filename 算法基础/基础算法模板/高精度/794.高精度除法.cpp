#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> A;

//A / b,商是C，余数是r 
vector<int> div(vector<int> &A, int x, int &r)//r是余数 
{
	//从高位往低位除
	vector<int> C;
 	
 	r = 0;
 	for(int i = A.size() - 1; i >= 0; i -- )
 	{
 		r = r * 10 + A[i];
 		C.push_back(r / x);
 		r %= x;
	}
	
	reverse(C.begin(), C.end());//将正序转换为倒序 
	while(C.size() > 1 && C.back() == 0) C.pop_back();//去除前导0 
	
	return C;
} 

int main()
{
	string a;
	int b;
	cin >> a >> b;
	//字符串有别忘记去'0' 
	for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
	
	int r;
	auto c = div(A, b, r);
	
	for(int i = c.size() - 1; i >= 0; i -- ) printf("%d", c[i]);
	printf("\n%d", r);
	
	return 0;
}

