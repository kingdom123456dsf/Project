#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> A;

vector<int> div(vector<int> &A, int b, int &y)//余数 
{
	vector<int> C;
	for(int i = A.size() - 1; i >= 0; i -- )//除法正序进行 
	{
		y = y * 10 + A[i];//当前的被除数
		
		C.push_back(y / b);
		y %= b; 
	}
	//因为是正序存了，所以翻转一下
	reverse(C.begin(), C.end()); 
	
	while(C.size() > 1 &&C.back() == 0) C.pop_back();
	
	return C;	
}

int main()
{
	int b;
	string s;
	cin >> s >> b;
	for(int i = s.size() - 1; i >= 0; i -- ) A.push_back(s[i] - '0');
	
	int y = 0;
	vector<int> C = div(A, b, y); 
	
	for(int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
	puts("");
	cout << y << endl;
	
	return 0;
}
