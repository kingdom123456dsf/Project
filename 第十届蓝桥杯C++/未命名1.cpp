#include<iostream>
#include<set> 

using namespace std;

typedef pair<double, double> pdd;
set<pdd> ss;

int main()
{
 	ss.insert({1.0, 2.0});
 	
 	for(auto t : ss)
 	{
 		cout << t.first << " " << t.second << endl;
	}
	
	cout << ss.insert({1.0, 2.0}).second;


	return 0;
}

