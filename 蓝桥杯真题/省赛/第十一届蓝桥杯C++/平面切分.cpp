#include<iostream>
#include<set> 

using namespace std;

typedef pair<double, double> pdd;

const int N = 1010;//��ʾ���Ա�������ʱ�临�ӶȲ��� 

set<pdd> lines;//�洢(б�ʣ� �ؾ�) 

int num(double a, double b)
{
	set<pdd> points;//�洢��������
	for(auto temp : lines)
	{
		double c = temp.first, d = temp.second;
		if(c != a)//����ֱ��б�ʲ��ȣ���ƽ�� �н���
		{
			double x1 = (d - b) / (a - c);
			double y1 = a * x1 + b;//���²����б�ʺͽؾ�����
			points.insert({x1, y1});
		} 
	} 
	return points.size();
}

int main()
{
	int n;
	cin >> n;
	
	int res = 1;//�ʼһ��ֱ�߾��� 1 + 0 + 1 
	for(int i = 0; i < n; i ++ )
	{
		double a, b;//���⾫������ 
		cin >> a >> b;//б�ʡ��ؾ�
		if(lines.insert({a, b}).second)//true��������ɹ������������ظ�Ԫ�� 
		{
			res += num(a, b) + 1;//ƽ����� = ��һ��ƽ������ + ������� + 1 
		}
	}
	
	cout << res << endl; 
	
	
	return 0;
}
