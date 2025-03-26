#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> A, B;

vector<int> mul(vector<int> &A, int x)//用&可以加快速度，不用再拷贝一遍数组
{
	vector<int> C;
	int t = 0;
	for(int i = 0; i < A.size(); i ++ )
	{
		t += A[i] * x;
		C.push_back(t % 10);
		t /= 10;
	}
	
	if(t) C.push_back(t);
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
	
	auto c = mul(A, b);
	
	for(int i = c.size() - 1; i >= 0; i -- ) printf("%d", c[i]);
	
	return 0;
}

