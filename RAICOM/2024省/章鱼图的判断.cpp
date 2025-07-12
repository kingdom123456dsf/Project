#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	srand(time(nullptr));
	
	int s = rand() % 10;
	
	cout << s << endl;
	
	
	return 0;
}
