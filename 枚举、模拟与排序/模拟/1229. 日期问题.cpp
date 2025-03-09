#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 默认为平年
int w[3];

int main() {
    char x;
    int n = 0;
    while (true) {
        cin >> w[n];
        n++;
        x = getchar();
        if (x != '/') break;
    }
    int a, b, c;
    a = w[0], b = w[1], c = w[2];

    string aa;
    if (a < 10) aa = "0" + to_string(a);
    else aa = to_string(a);

    string bb;
    if (b < 10) bb = "0" + to_string(b);
    else bb = to_string(b);

    string cc;
    if (c < 10) cc = "0" + to_string(c);
    else cc = to_string(c);

    vector<string> validDates;

    for (int i = 1960; i <= 2059; i++) {
        int year = i % 100; // 得到年份后两位
        if (a == year) { // 年月日
            if (b >= 1 && b <= 12) {
                if (b == 2) {
                    bool check = (i % 4 == 0 && i % 100 != 0) || (i % 400 == 0); // 判断闰年
                    if (c <= days[2] + check && c > 0) {
                        string date = to_string(i) + "-" + bb + "-" + cc;
                        validDates.push_back(date);
                    }
                } else {
                    if (c <= days[b] && c > 0) {
                        string date = to_string(i) + "-" + bb + "-" + cc;
                        validDates.push_back(date);
                    }
                }
            }
        }

        if (c == year) {
            if (a >= 1 && a <= 12) { // 月日年
                if (a == 2) {
                    bool check = (i % 4 == 0 && i % 100 != 0) || (i % 400 == 0); // 判断闰年
                    if (b <= days[2] + check && b > 0) {
                        string date = to_string(i) + "-" + aa + "-" + bb;
                        validDates.push_back(date);
                    }
                } else {
                    if (b <= days[a] && b > 0) {
                        string date = to_string(i) + "-" + aa + "-" + bb;
                        validDates.push_back(date);
                    }
                }
            }

            if (b >= 1 && b <= 12) { // 日月年
                if (b == 2) {
                    bool check = (i % 4 == 0 && i % 100 != 0) || (i % 400 == 0); // 判断闰年
                    if (a <= days[2] + check && a > 0) {
                        string date = to_string(i) + "-" + bb + "-" + aa;
                        validDates.push_back(date);
                    }
                } else {
                    if (a <= days[b] && a > 0) {
                        string date = to_string(i) + "-" + bb + "-" + aa;
                        validDates.push_back(date);
                    }
                }
            }
        }
    }

    // 对存储日期的 vector 进行排序
    sort(validDates.begin(), validDates.end());
    auto last = unique(validDates.begin(), validDates.end());
    validDates.erase(last, validDates.end());

    // 输出排序后的日期
    for (const string& date : validDates) {
        cout << date << endl;
    }

    return 0;
}
