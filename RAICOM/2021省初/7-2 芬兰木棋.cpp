#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
vector<PII> g;
int n;

int main()
{
	cin >> n;
	
	int sum = 0;
	for(int i = 0; i < n; i ++)
	{
		int x, y, p;
		cin >> x >> y >> p;
		sum += p;
		
		if(p == 1) g.push_back({x, y});
	}
	
	cout << sum << " " << n - int(g.size()) + 1 << endl;
	
	return 0;
}
