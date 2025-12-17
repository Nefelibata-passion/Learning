//3.17 按1的个数排序
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool myComp(const string &s1, const string &s2) {
    int c1 = count(s1.begin(), s1.end(), '1');
    int c2 = count(s2.begin(), s2.end(), '1');
    //彻底修改排序规则，只按1的数量排序
    //如果1的数量相等，则按出现的先后顺序
    //否则，会按ASCII码大小排序
    //只能用“>”或“<”，不能用“=”
    return c1 != c2? c1 < c2 : c1 < c2;
}

int main() {
    //ifstream cin("aaa.txt");
    vector<string> vstr;
    string str;
    while(cin >> str) {
        vstr.push_back(str);
    }
    sort(vstr.begin(), vstr.end(), myComp);
    for(vector<string>::iterator it = vstr.begin(); it < vstr.end(); it++) 
        cout << *it << endl;
    return 0;
}