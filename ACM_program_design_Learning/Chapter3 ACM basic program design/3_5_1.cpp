//3.5 斐波那契数列
//先把第0项到第46项的斐波那契数列求出来，放在一个表（或数组）中，
//然后，直接查表即可，这样就不会超时

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//(1) 采用数组来做

int main() {
    //ifstream cin("aaa.txt");
    int a[47];
    a[0] = 0;
    a[1] = 1;
    //先把前46项斐波那契数列求出来放在表（或数组）中
    for(int i = 2; i <= 46; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    //查表（数组）
    int n;
    while(cin >> n) {
        cout << a[n] << endl;
    }
    return 0;
}