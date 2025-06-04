#include<iostream>

using namespace std;

int n;
int c, p;
int j[2], y[2], t[2];

bool check()//一是否赢 
{
	if(j[0] != j[1]) return j[0] > j[1];
	else
	{
		if(y[0] != y[1]) return y[0] > y[1];
		else
		{
			return t[0] > t[1];
		}
	} 
}

int main()
{
	cin >> n;
	
	while(n -- )
	{
		cin >> c >> p;
		if(c == 0)//一 
		{
			if(p == 1) j[0] ++ ;
			else if(p == 2) y[0] ++ ;
			else t[0] ++ ;
		}
		else//二 
		{
			if(p == 1) j[1] ++ ;
			else if(p == 2) y[1] ++ ;
			else t[1] ++ ;
		}
	}
	
	cout << j[0] << " " << y[0] << " " << t[0] << endl;
	cout << j[1] << " " << y[1] << " " << t[1] << endl;
	if(check())
	{
		cout << "The first win!" << endl;
	}
	else cout << "The second win!" << endl;
	
	return 0;
}
