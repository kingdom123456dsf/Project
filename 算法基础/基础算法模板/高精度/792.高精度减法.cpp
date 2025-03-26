#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> A, B;

bool cmp(vector<int> &A, vector<int> &B)
{
	if(A.size() < B.size()) return false;
	
	if(A.size() == B.size())
	{
		for(int i = A.size() - 1; i >= 0; i -- )
		{
			if(A[i] != B[i])
			{
				if(A[i] > B[i]) return true;
				else return false;
			}
		}
	}
	
	return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)//用&可以加快速度，不用再拷贝一遍数组
{
	vector<int> C;//C = A - B
	int t = 0;//借位 
	for(int i = 0; i < A.size(); i ++ )
	{
		t = A[i] - t;
		if(i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);//处理正负的个位数两种情况
		if(t < 0) t = 1;//借位 
		else t = 0; 
 	}
 	
 	while(C.size() > 1 && C.back() == 0) C.pop_back();//去除前导0 
 	return C;
} 

int main()
{
	string a, b;
	cin >> a >> b;
	//字符串有别忘记去'0' 
	for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
	for(int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');
	
	if(cmp(A, B))//A >= B
	{
		auto c = sub(A, B);
	
		for(int i = c.size() - 1; i >= 0; i -- ) printf("%d", c[i]);
	}
	else//小减大，有负号 
	{
		auto c = sub(B, A);
		
		printf("-");
		for(int i = c.size() - 1; i >= 0; i -- ) printf("%d", c[i]);
	}
	
	return 0;
}

