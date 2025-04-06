#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

typedef pair<double, double> pdd;

set<pdd> line;

int main()
{
	//直接枚举两点坐标
	for(int x1 = 0; x1 < 20; x1 ++ )
		for(int y1 = 0; y1 < 21; y1 ++ )
			for(int x2 = 0; x2 < 20; x2 ++ )
				for(int y2 = 0; y2 < 21; y2 ++ )
				{
					if(x1 != x2)//垂直的最后结果加二十即可
					{
						double k = (double)(y2 - y1) / (x2 - x1);
						//double b = y2 - k * x2;避免损失精度
						double b = double(x2 * y1 - x1 * y2) / (x2 - x1); 
						line.insert({k, b});//自动去重 
					} 
				}	

	cout << line.size() + 20 << endl;//加上k = 0的也就是与x轴垂直的20条直线 
	
	return 0;
} 
