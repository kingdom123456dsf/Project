#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

typedef pair<double, double> pdd;

set<pdd> line;

int main()
{
	//ֱ��ö����������
	for(int x1 = 0; x1 < 20; x1 ++ )
		for(int y1 = 0; y1 < 21; y1 ++ )
			for(int x2 = 0; x2 < 20; x2 ++ )
				for(int y2 = 0; y2 < 21; y2 ++ )
				{
					if(x1 != x2)//��ֱ��������Ӷ�ʮ����
					{
						double k = (double)(y2 - y1) / (x2 - x1);
						//double b = y2 - k * x2;������ʧ����
						double b = double(x2 * y1 - x1 * y2) / (x2 - x1); 
						line.insert({k, b});//�Զ�ȥ�� 
					} 
				}	

	cout << line.size() + 20 << endl;//����k = 0��Ҳ������x�ᴹֱ��20��ֱ�� 
	
	return 0;
} 
