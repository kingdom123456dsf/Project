#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	//��Ҫ���ߵ�x = 705.581321,�ټ��㻡���ߵ���(233, 666) 
	int res = 0;
	double a = 233, b = 666;
	double r = sqrt(a * a + b * b);
	printf("�뾶Ϊ:%lf\n", r);
	double w = 666.0 / 233.0;
	printf("����Ϊ:%lf\n", atan(w));
	double pi = acos(-1);
	printf("�Ƕ�Ϊ:%lf\n", atan(w) * 180 / pi);
	printf("��Ϊ:%lf",  70.72 * pi * r / 180  + r);
	//���Ƚ�Ϊ70.717618255317496200585716773196��
	//����Ϊ n2��r/360 ,nΪ���Ƚ� 
	
	return 0;
}
