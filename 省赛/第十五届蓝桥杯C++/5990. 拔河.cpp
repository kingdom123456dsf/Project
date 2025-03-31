#include<iostream>
#include<algorithm>
#include<set>

typedef long long LL;

using namespace std;

const int N = 1010;
LL a[N];
multiset<LL> ranges;
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		a[i] += a[i - 1];//ǰ׺�ʹ��� 
	}
	
	//����߽��ж� 
	ranges.insert(1e13), ranges.insert(-1e13);//��ǰ��һ�������Сֵ
	LL res = 1e9; 
	for(int l = 1; l <= n; l ++ )//ö�����������߽� 
	{
		for(int i = 1; i <= l - 1; i ++)//[i, l - 1]//����������� 
		{
			ranges.insert(a[l - 1] - a[i - 1]);
		}
		for(int r = l; r <= n; r ++)//��������ұ߽� 
		{
			LL sum = a[r] - a[l - 1];//������Ĵ�С
			auto it = ranges.lower_bound(sum);//���֣��ҵ����ڵ���������Сֵ
		 	res = min(res, *it - sum);
		 	it --;//С�ڵ����������ֵ
		 	res = min(res, sum - *it);
		}
	}
	
	cout << res << endl;
	
	return 0;
}
