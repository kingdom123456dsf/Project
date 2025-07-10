#include<iostream>

using namespace std;

int j1, y1, t1, j2, y2, t2;

bool check()
{
	if(j1 != j2) return j1 > j2;
	if(y1 != y2) return y1 > y2;
	else return t1 > t2;
}

int main()
{
	int n;
	cin >> n;
	
	while(n -- )
	{
		int x, y;
		cin >> x >> y;
		if(x == 0)
		{
			if(y == 1) j1 ++ ;
			if(y == 2) y1 ++ ;
			if(y == 3) t1 ++ ;
		}
		if(x == 1)
		{
			if(y == 1) j2 ++ ;
			if(y == 2) y2 ++ ;
			if(y == 3) t2 ++ ;
		}
	}
	
	cout << j1 << " " << y1 << " " << t1 << endl;
	cout << j2 << " " << y2 << " " << t2 << endl;
	
	if(check()) cout << "The first win!" << endl;
	else cout << "The second win!" << endl;
	
	return 0;
}
