#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> A, B;

vector<int> add(vector<int> &A, vector<int> &B)//��&���Լӿ��ٶȣ������ٿ���һ������
{
	vector<int> C;
	int t = 0;//��¼ÿһλ
	
	for(int i = 0; i < A.size() || i < B.size(); i ++ )
	{
		if(i < A.size()) t += A[i];
		if(i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	
	if(t) C.push_back(t);
	return C;
} 

int main()
{
	string a, b;
	cin >> a >> b;
	//�ַ����б�����ȥ'0' 
	for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
	for(int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');
	
	auto c = add(A, B);
	
	for(int i = c.size() - 1; i >= 0; i -- ) printf("%d", c[i]);
	
	return 0;
}
