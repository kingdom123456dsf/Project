#include<iostream>
#include<queue>

using namespace std;

const int N = 100010;
int a[N], hh, tt = - 1;//Í·ºÍÎ² 

int main()
{
	int m;
	scanf("%d", &m);
	string str;
	int x;
	while(m --)
	{
		cin >> str;
		if(str == "push")
		{
			scanf("%d", &x);
			a[++ tt] = x;
		}
		else if(str == "pop")
		{
			hh ++;
		}
		else if(str == "query")
		{
			printf("%d\n", a[hh]);
		}
		else if(str == "empty")
		{
			if(hh > tt)
			{
				printf("%s\n", "YES");
			}
			else printf("%s\n", "NO"); 
		}
	}
	
	return 0;
}
