//3.13 五位以内的对称素数
#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int n) {//判断是否是素数
    if(n == 1)
        return false;
    if(n != 2 && n % 2 == 0)
        return false;
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0)
            return false;
    }
    return true;
}

bool isSym(int n) {
    //一位数的素数和11都算是对称的
    if(n < 12 && n!= 10) 
        return true;
    //三位数素数是否对称
    if(n > 100 && n < 1000 && n/100 == n %10) 
        return true;
    //四位数的对称数，不可能是素数
    //假设四位对称数abba, 即1000a + 100b + 10b + a = 11(91a +10b)
    //具有因子11所以是合数
    //判断五位素数是否对称
    if(n > 10000 && n < 100000 && n / 10000 == n%10*10 + n/10%10)
        return true;
    return false;
}

int main() {
    //ifstream cin("aaa.txt");
    int n;
    while(cin >> n) {
        cout << (isSym(n) && isPrime(n)? "Yes\n" : "No\n");
    }
    return 0;
}