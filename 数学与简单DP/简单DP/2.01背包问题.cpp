#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;
int f[N][N];//�����ֵ 
int v[N],w[N];
int n,vt;

//��ά���飬����д�� 
int main(){
	cin >> n >> vt;
	for(int i = 1;i <= n;i++) cin >> v[i] >> w[i];
	
	for(int i = 1;i <= n;i++)//����ڼ�����Ʒ 
		for(int j = 0;j <= vt;j++)//����ǰ����� 
		{
			f[i][j] = f[i - 1][j];//��ѡ��i��
			if(j >= v[i])
		 		f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);	
		}
		
	cout << f[n][vt] << endl;
	
	
	return 0;
}

//һά���飬�Ż��ռ�д�� 
 /*cin >> n >> vt;
    for(int i = 1;i <= n;i++) cin >> v[i] >> w[i];

    for(int i = 1;i <= n;i++)//����ڼ�����Ʒ 
        for(int j = vt;j >= v[i];j--)//����ǰ����� 
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);   
        }

    cout << f[vt] << endl; */

