#include<iostream>
#include<set>

using namespace std;

typedef long long LL;//2^63 - 1

int main()
{
	//����������������������3�ͺ�(����)
 	LL target;//2021041820210418
// 	cin >> target;
	target = 2021041820210418;
  
	LL res = 0;
	for(LL i = 1; i * i * i <= target; i ++ )
	{
		if(target % i == 0)//�����ǰi�ǽ������ 
		{
			for(LL j = i; i * j * j <= target; j ++ )
			{
				if(target / i % j == 0)//jҲ�ǽ����
				{
					LL k = target / i / j;//����һ��ѭ���ĸ��Ӷ�
					if(i == j && j == k) res ++;//��������Ⱦ�һ������
					else if(i != j && j != k) res += 6;//A32(ȫ���У�������������)
					else res += 3;//C31,��գ�����������ȣ� 
				} 
			}
		}
	}
	
	cout << res << endl;
	
	return 0;
}
