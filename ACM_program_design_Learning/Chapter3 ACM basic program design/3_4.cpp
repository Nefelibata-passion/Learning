//3.4 等比数列

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    //ifstream cin("aaa.txt");
    //定点输出小数点后3位；否则是输出有效数字3位
    cout.precision(3);
    int n;
    double q, sum;
    while(cin >> n >> q) {
        if(q == 1)  sum = 1 + n;
        else
            sum = (1 - pow(q, n + 1))/(1 - q);
        //使用fixed，定点输出，即小数点后的精度是3位
        cout << fixed << sum << endl;
    }
}