 #include<iostream>
 #include<algorithm>
 #include<cstring>
 
 using namespace std;
 
 const int N = 10010;
 int n;
 
 bool check(int x)
 {
 	while(x)
 	{
 		int t = x % 10;
 		if(t == 1 || t == 2 || t == 0 || t == 9) return true;
 		x /= 10;
 	}
 	return false;
 }
 
 int main()
 {
 	cin >> n;
 	int res = 0;
 	for(int i = 1; i <= n; i++)
 	{
 		if(check(i)) res += i;
 	}
 	
 	cout << res << endl;
 	
 	return 0;
 }
