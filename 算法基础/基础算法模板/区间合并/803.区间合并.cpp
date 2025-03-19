#include<iostream>
#include<cstring>
#include<algorithm> 
#include<vector>

using namespace std;

typedef pair<int, int> PII;

vector<PII> segs;

void merge(vector<PII> &segs)
{
	vector<PII> res;
	
	sort(segs.begin(), segs.end());//���������� ������ 
	
	int st = -2e9, ed = -2e9;//��㣬�յ�
	for(auto seg : segs)
	{
		if(ed < seg.first)//�����˵� 
		{
			if(st != -2e9) res.push_back({st, ed});
			st = seg.first, ed = seg.second;
		}
		else ed = max(ed, seg.second);//���º�˵�,������ȡ��󣡣��� 
	}
	
	if(st != -2e9)//��segsΪ��
		res.push_back({st, ed});
	
 	segs = res;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		segs.push_back({l, r});
	}
	
	merge(segs);
	
	cout << segs.size() << endl;
	
	return 0;
}
