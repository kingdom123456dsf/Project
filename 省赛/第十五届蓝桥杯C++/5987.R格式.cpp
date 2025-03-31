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
	while(A.size() > 1 && A.back() == 0) A.pop_back();//ȥ��ǰ��0 
}

void add(vector<int> &A, int pos)
{
	int t = 1;//��������λ 
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
	
	reverse(s.begin(), s.end());//����
	
	int pos = s.find('.');
	for(int i = 0; i < s.size(); i ++ )
	{
		if(s[i] != '.') A.push_back(s[i] - '0');
	} 
	
	while(n --) mul(A, 2);
	
	if(A[pos - 1] >= 5) add(A, pos);//�������룬��λ 
	
	for(int i = A.size() - 1; i >= pos; i -- ) cout << A[i];
	
	return 0;
}
