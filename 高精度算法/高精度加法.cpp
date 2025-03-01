#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N = 100005;
int A[N], B[N], C[N];
int la, lb, lc;

void add(int A[], int B[], int C[])
{
	for (int i = 0; i < lc; i++)
	{
		C[i] += A[i] + B[i];//�ۼ�
		C[i + 1] += C[i] / 10;//��λ
		C[i] %= 10;//����
	}
	if (C[lc]) lc++;
	//while (C[lc - 1] == 0 && lc > 0) lc--;//��ֹ��ǰ�����Ϊ0������0199
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	la = s1.size();
	lb = s2.size();
	lc = max(la, lb);

	//����洢ת����
	for (int i = 0; i < la; i++)
		A[la - 1 - i] = s1[i] - '0';
	for (int i = 0; i < lb; i++)
		B[lb - 1 - i] = s2[i] - '0';

	add(A, B, C);
	//�������
	for (int i = lc - 1; i >= 0; i--) cout << C[i];
	cout << endl;

	system("pause");
	return 0;
}