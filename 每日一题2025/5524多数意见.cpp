#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 100010;

int h[N];

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> h[i];
		
		vector<int> res;
		if(n == 2)
		{
			if(h[0] == h[1]) cout << h[0] << endl;
			else cout << "-1" << endl;
			continue;
		} 
		for(int i = 2; i < n; i++)
		{
			if(h[i - 2] == h[i] || h[i - 1] == h[i])
   				res.push_back(h[i]);
			if(h[i - 1] == h[i - 2] && h[i - 1] != h[i])
   				res.push_back(h[i - 1]);
		}
		
		/*for(int i = 1;i < n - 1;i++)
		{
			if(h[i] == h[i - 1] || h[i] == h[i + 1])
				res.push_back(h[i]);
			if(h[i - 1] == h[i + 1] && h[i] != h[i - 1])
				res.push_back(h[i - 1]);
		}*/
		
		int x = res.size();
		if(x)
		{
			sort(res.begin(), res.end());
			// ʹ�� std::unique ���ظ�Ԫ���Ƶ�����ĩβ��������ָ���һ���ظ�Ԫ�صĵ�����
   			auto last = std::unique(res.begin(), res.end());
    		// ɾ���ظ�Ԫ��
    		res.erase(last, res.end());
    		
			for(auto a : res)
				cout << a << " " ;
			cout << endl;
		}
		else cout << "-1" << endl;
	}
	
	return 0;
}
