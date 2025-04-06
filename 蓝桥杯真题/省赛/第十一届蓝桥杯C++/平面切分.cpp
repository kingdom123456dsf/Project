#include<iostream>
#include<set> 

using namespace std;

typedef pair<double, double> pdd;

const int N = 1010;//按示可以暴力做，时间复杂度不大 

set<pdd> lines;//存储(斜率， 截距) 

int num(double a, double b)
{
	set<pdd> points;//存储交点坐标
	for(auto temp : lines)
	{
		double c = temp.first, d = temp.second;
		if(c != a)//两条直线斜率不等，不平行 有交点
		{
			double x1 = (d - b) / (a - c);
			double y1 = a * x1 + b;//用新插入的斜率和截距来算
			points.insert({x1, y1});
		} 
	} 
	return points.size();
}

int main()
{
	int n;
	cin >> n;
	
	int res = 1;//最开始一条直线就是 1 + 0 + 1 
	for(int i = 0; i < n; i ++ )
	{
		double a, b;//避免精度问题 
		cin >> a >> b;//斜率、截距
		if(lines.insert({a, b}).second)//true则代表插入成功，集合中无重复元素 
		{
			res += num(a, b) + 1;//平面个数 = 上一次平面数量 + 交点个数 + 1 
		}
	}
	
	cout << res << endl; 
	
	
	return 0;
}
