//3.15 排列对称串
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//自己设计排序比较函数
bool Comp(const string &s1, const string &s2) {
    return s1.length() != s2.length() ? s1.length() < s2.length() : s1 < s2;
}

int main() {
    //ifstream cin("aaa.txt");
    vector<string> v;
    string t, s;
    while(cin >> s) {
        t = s;
        //反转字符串,用来判断字符是否对称
        reverse(t.begin(), t.end());
        if(t == s) {
            v.push_back(s);
        }
    }
    //按Comp函数比较规则排序
    sort(v.begin(), v.end(), Comp);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}