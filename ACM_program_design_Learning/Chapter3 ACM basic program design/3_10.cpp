//3.10 十进制转换为二进制
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string s;//全局变量
int main() {
    //ifstream cin("aaa.txt");
    int n;
    while(cin >> n) {
        if(n == 0) {
            cout << "          0-->0\n";
            continue;
        }
        s="";
        for(int a = n; a; a /= 2) {
            s +=(a % 2? '1' : '0' );
        }
        std::reverse(s.begin(), s.end());
        const char *sss = s.c_str();
        cout.width(11); //输出宽度为11
        cout << n <<(n < 0? "-->-" : "-->") << sss << "\n";
    }
}