#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int mid[N * 2];//�е���� ,Ϊʲô��2,��Ϊ�е�l + r / 2�����Ƿ���,����ֱ�Ӷ���������ͽ�����������
 
int main()
{
	int n, m;
	cin >> n >> m;
	
	while(n -- )
	{
		int l, r;
		cin >> l >> r;
		mid[l + r] ++ ;//ֱ�Ӹ��е� * 2,����������� 
	}
	
	for(int i = 1; i < N * 2; i ++ )
	{
		mid[i] += mid[i - 1];//ǰ׺�����飬���ں���ͳ���ж����е��������� 
	}	
	
	while(m -- )
	{
		LL res = 0;
		int l, r;
		cin >> l >> r;
		res += mid[r * 2] - mid[l * 2 - 1];
		cout << res << endl;
	}		
	
	return 0;
}
