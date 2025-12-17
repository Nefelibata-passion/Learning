//3.14 01串排序
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct Comp{
    bool operator() (const string &s1, const string &s2) const {
        if(s1.length() != s2.length())
            return s1.length() < s2.length();
        int c1 = count(s1.begin(), s1.end(), '1');
        int c2 = count(s2.begin(), s2.end(), '1');
        return (c1 != c2? c1 < c2 : s1 < s2);
    }
};

int main() {
    multiset<string, Comp> ms;
    //ifstream cin("aaa.txt");
    string s;
    while(cin >> s) {
        ms.insert(s);
    }
    for(multiset<string, Comp>::iterator it = ms.begin(); it != ms.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}