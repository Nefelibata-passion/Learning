//3.7 最小公倍数

#include <iostream>
#include <fstream>

using namespace std;
//声明gcd函数，该函数用来计算两数的最大公约数
int gcd(int, int);

int main() {
    //ifstream cin("aaa.txt");
    int x, y;
    while(cin >> x >> y) {
        cout << x/gcd(x, y) * y << endl;
    }
    return 0;
}

int gcd(int x, int y) {
    while(x != y) {
        if(x > y) 
            x = x - y;
        else 
            y = y - x;
    }
    return x;
}