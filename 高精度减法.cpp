#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s1, s2;
int a[10000], b[10000], c[10000];

int main() {
	
	cin >> s1 >> s2;

	//�жϴ�С,s1�����s2 
	if (s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2) {
		swap(s1, s2); //����ֵ
		cout << "-";
	}

	int len1 = s1.size();
	int len2 = s2.size();

	//����洢
	for (int i = 0; i < len1; i++) {
		a[i] = s1[len1 - i - 1] - '0';
	}
	for (int i = 0; i < len2; i++) {
		b[i] = s2[len2 - i - 1] - '0';
	}

	//����
	for (int i = 0; i < len1; i++) {
		if (a[i] < b[i]) {
			a[i + 1]--; //��λ��1
			a[i] += 10; // ��λ��10 
		}
		c[i] = a[i] - b[i];
	}

	//ȥ��ǰ����
	while (c[len1 - 1] == 0 && len1 > 1) {
		len1--;
	}

	//���
	for (int i = len1 - 1; i >= 0; i--) {
		cout << c[i];
	}

	system("pause");
	return 0;
}