#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s1, s2;
int a[100005], b[100005], c[100005];

int main() {
	
	cin >> s1 >> s2;

	//判断大小,s1恒大于s2 
	if (s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2) {
		swap(s1, s2); //交换值
		cout << "-";
	}

	int len1 = s1.size();
	int len2 = s2.size();

	//倒序存储
	for (int i = 0; i < len1; i++) {
		a[i] = s1[len1 - i - 1] - '0';
	}
	for (int i = 0; i < len2; i++) {
		b[i] = s2[len2 - i - 1] - '0';
	}

	//减法
	for (int i = 0; i < len1; i++) {
		if (a[i] < b[i]) {
			a[i + 1]--; //上位减1
			a[i] += 10; // 本位加10 
		}
		c[i] = a[i] - b[i];
	}

	//去除前导零
	while (c[len1 - 1] == 0 && len1 > 1) {
		len1--;
	}

	//输出
	for (int i = len1 - 1; i >= 0; i--) {
		cout << c[i];
	}

	system("pause");
	return 0;
}
