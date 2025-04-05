#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	// >= 60则及格, >= 85则优秀
	int n;
	scanf("%d", &n);
	double yx, jg = 0;
	for(int i = 0; i < n; i ++ )
	{
		int x;
		scanf("%d", &x);
		if(x >= 85)
		{
			yx ++;
			jg ++;
		}
		else if(x >= 60 && x < 85)
		{
			jg ++;
		}
	}
	
	printf("%.lf%\n", jg / n * 100);
	printf("%.lf%\n", yx / n * 100);
		
	return 0;
}
