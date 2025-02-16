#include<iostream>

using namespace std;

int main(){
    int p, q;
    cin >> p >> q;
    
    int res = (q - 1) * (p - 1) - 1;
    cout << res << endl;
    
    return 0;
}
