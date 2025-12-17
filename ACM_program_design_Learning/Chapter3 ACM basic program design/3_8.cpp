//3.8 平均数
//求平均数，保留小数点后三位，需要四舍五入
//cout << precision(3);
//cout << fixed << sum/n << endl;

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    //ifstream cin("aaa.txt");
    int n, x;
    double sum;
    cout.precision(3); //输出精确到小数点后三位，四舍五入
    while(cin >> n) {
        sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
        }
        //定点输出小数点后三位
        cout << fixed << sum/n << endl;
    }
    return 0;
}
