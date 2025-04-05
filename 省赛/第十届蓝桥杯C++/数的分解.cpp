#include<iostream>

using namespace std;

bool check(int x)//ÅÐ¶ÏÊÇ·ñ°üº¬2¡¢4 
{
    int t = 0;
	while(x)
	{
		t = x % 10;
		if(t == 2 || t == 4) return false;
		x /= 10;
	}
	return true;
}

int main()
{
	// 1 ~ 1999
    for(int i = 1; i < 2000; i ++ )
    {
        for(int j = i + 1; j < 2000; j ++ )
        {
            for(int k = j + 1; k < 2000; k ++ )
            {
                int a = i, b = j, c = k;
                if(!check(a) || !check(b) || !check(c)) continue;
                
                int res = a + b + c;
                if(res == 2019)
                {
                    cout << a << " " << b << " " << c << endl;
                }
            }
        }
    }
	
	
	return 0;
}
