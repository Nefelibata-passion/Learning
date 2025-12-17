//3.2读入两个参数

#include <fstream>
#include <iostream>
using namespace std;

int main() {
    //ifstream cin("aaa.txt");
    int a, b;
    while(cin >> a >> b) {
        cout << a - b << endl;
    }
    return 0;
}