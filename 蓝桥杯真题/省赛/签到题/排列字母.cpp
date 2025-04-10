#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	char s[] = "WHERETHEREISAWILLTHEREISAWAY";
//	string s = "WHERETHEREISAWILLTHEREISAWAY";

//	sort(s.begin(), s.end());

	int n = strlen(s);
	sort(s, s + n);
	cout << s << endl;
	
	return 0;
}
