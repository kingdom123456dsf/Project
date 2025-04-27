#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int N = 1e3 + 10;
vector<int> G[N];//�ڽӱ� 
int a[N];//Ȩֵ 

set<int> dfs(int p, int fa)//p����ǰ�ڵ�,fa����ǰ�ڵ�ĸ��ڵ� 
{
	//����ǰΪҶ�ӽ�� �� ��Ϊ���ڵ�
	//���ص�ǰ�ڵ��Ȩֵ�Ҳ�ѡȡ�κνڵ� 
	if(G[p].size() == 1 && fa != 0) return {a[p], 0};//����������Ԫ�ش���ѡ��ѡ��ǰҶ�ӽ�� 
	
	set<int> s = {0};//���Դ���ĳ�Ʒ��λ 
	
	for(auto &it : G[p])//������ǰ�ڵ�p���ڽӽڵ�,Ҳ�����ӽڵ� 
	{
		if(it == fa) continue;//��Ϊ���ڵ㣬�����������ⷴ������ 
		//����dp
		auto v = dfs(it, p);//����(��������)
		set<int> tmp = s;//���Ƶ�ǰ���� s �� tmp�������ڱ��� s �Ĺ������޸� s ���µ�����ʧЧ
		for(auto &x : tmp)
		{
			for(auto &y : v)
			{
				if(x + y > a[p]) break;//������������ 
				s.insert(x + y);//���������𰸼� 
			}
		} 
	}
	return s;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	for(int i = 1; i <= n - 1; i ++ )//n���ڵ������n - 1���� 
	{
		int x, y;
		cin >> x >> y;
		//��Ϊ��������ͼ,����˫���,�����ڵ�����໥���� 
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	//�Ӹ��ڵ㿪ʼ�ݹ� 
	cout << *dfs(1, 0).rbegin();//��Ϊ1,û�и��ڵ�(Ϊ0) 
	//���ش𰸼��������Ǹ����
	
	return 0;
}
