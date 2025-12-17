//3.9 对称三位数素数
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
//isPrime函数用来判断一个数是否是素数

bool isPrime(int);

int main() {
    //ifstream cin("aaa.txt");
    int n;
    while(cin >> n) {
        cout << (n > 100 && n < 1000 && n / 100 == n %10 && isPrime(n)?"Yes\n":"No\n");
    }
    return 0;
}

bool isPrime(int n) {
    //sqrt开方，需要#include <cmath>
    int sqr = sqrt(n * 1.0);
    for(int i = 2; i <= sqr; i++) {
        if(n%i == 0)
            return false;
    }
    return true;
}