#include<iostream>

using namespace std;

//�洢�·ݵ�����,Ĭ��Ϊƽ�� 
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//�ж������Ƿ�Ϸ� 
bool is_valid(int x)
{
	int year = x / 10000;
	int month = x % 10000 / 100;
	int day = x % 100;
	
	//���ж�Խ������ 
	if(month < 1 || month > 12 || day < 1 || day > 31) return false;
	
	if(month != 2)
	{
		if(day > days[month]) return false;
	}
	else//2�� 
	{
		bool deap = year % 4 == 0 && year % 100 || year % 400 == 0;//�ж����껹��ƽ�� 
		if(day > days[2] + deap) return false;	
	}
	
	return true;
}

int main()
{
	int res = 0;//ǧ�� 
	int t = 6;//��¼����,һ��7��,ֱ�Ӹ�tģ7���� 
	//ö������1��1�յ�10��1��
	for(int i = 20000101; i <= 20201001; i ++ )//ö�����е�����
	{
		if(is_valid(i))//��ǰ���ںϷ� 
		{
			int day = i % 100;
			if(day == 1 || t == 1)
			{
				res += 2;
			}
			else
			{
				res += 1;
			}
			t = (t + 1) % 7;
		}
	} 
	cout << res << endl;	
	
	return 0;
}
