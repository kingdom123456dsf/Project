#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> A;

vector<int> div(vector<int> &A, int b, int &y)//���� 
{
	vector<int> C;
	for(int i = A.size() - 1; i >= 0; i -- )//����������� 
	{
		y = y * 10 + A[i];//��ǰ�ı�����
		
		C.push_back(y / b);
		y %= b; 
	}
	//��Ϊ��������ˣ����Է�תһ��
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
