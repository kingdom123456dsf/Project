#include<iostream>

using namespace std;

int main()
{
	//-1, 0 , 1
	//�������Ժ���������������
	//��0��ʼ�Ϳ��� 
	int n;
	cin >> n;
	
	int res = n;
	for(int i = 0; i < n; i ++ )
	{
		int x;
		cin >> x;
		if(x == 1) res --;//����1�Ϳɷֽ� 
	}
	cout << res << endl;
	
	return 0;
}
