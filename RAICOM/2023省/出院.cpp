#include<iostream>
#include<cstring>
#include<map>

using namespace std;

int n, m;
map<string, char> mp;

int main()
{
	cin >> n >> m;
	string name;
	char value;
	while(n -- )
	{
		cin >> name >> value;
		mp[name] = value;
	}
	
	string s;
	while(m -- )
	{
		cin >> s;
		if (mp.find(s) != mp.end())//��һģһ���� 
        {
            cout << mp[s] << endl;
        }
        else//ƴ�ӵ� 
        {
            int x = 0;//��¼�ڼ���λ�ÿ�ʼ�ָ� 
            int cnt = 0;//�ж��ظ� 
            for (int i = 0; i < s.size(); i++)
            {
            	//��ƴ�ӵ� 
                if (mp.find(s.substr(0, i + 1)) != mp.end() && mp.find(s.substr(i + 1)) != mp.end())
                {
                    cnt ++ ;
                    x = i;
                }
            }
            if (!cnt || cnt > 1)//������ƴ�ӻ����ظ� 
                cout << "D" << endl;
            else//������������ 
            {
                cout << mp[s.substr(0, x + 1)] << mp[s.substr(x + 1)] << endl;
            }
        }
    }
	
	return 0;
}
