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

vector<int> sub(vector<int> &A, vector<int> &B)//��&���Լӿ��ٶȣ������ٿ���һ������
{
	vector<int> C;//C = A - B
	int t = 0;//��λ 
	for(int i = 0; i < A.size(); i ++ )
	{
		t = A[i] - t;
		if(i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);//���������ĸ�λ���������
		if(t < 0) t = 1;//��λ 
		else t = 0; 
 	}
 	
 	while(C.size() > 1 && C.back() == 0) C.pop_back();//ȥ��ǰ��0 
 	return C;
} 

int main()
{
	string a, b;
	cin >> a >> b;
	//�ַ����б�����ȥ'0' 
	for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
	for(int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');
	
	if(cmp(A, B))//A >= B
	{
		auto c = sub(A, B);
	
		for(int i = c.size() - 1; i >= 0; i -- ) printf("%d", c[i]);
	}
	else//С�����и��� 
	{
		auto c = sub(B, A);
		
		printf("-");
		for(int i = c.size() - 1; i >= 0; i -- ) printf("%d", c[i]);
	}
	
	return 0;
}

