#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> A, B;

vector<int> mul(vector<int> &A, int x)//��&���Լӿ��ٶȣ������ٿ���һ������
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
	while(C.size() > 1 && C.back() == 0) C.pop_back();//ȥ��ǰ��0 
	return C;	
} 

int main()
{
	string a;
	int b;
	cin >> a >> b;
	//�ַ����б�����ȥ'0' 
	for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
	
	auto c = mul(A, b);
	
	for(int i = c.size() - 1; i >= 0; i -- ) printf("%d", c[i]);
	
	return 0;
}

