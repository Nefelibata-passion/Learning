//3.12 12!配对
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int main() {
    //ifstream cin("aaa.txt");
    int num = 0;
    int f12 = 479001600;
    //多重集合，允许值重复
    multiset<unsigned int> s;
    int n;
    while(cin >> n) {
        if(f12 % n == 0) {  //n是f12的约数吗？
            //多重集合中有n的因子吗
            multiset<unsigned int>::iterator it = s.find(f12/n);
            if(it != s.end()) {
                num++;
                s.erase(it); //从多重集合中删除该因子
            }
            else
                s.insert(n); //插入到多重集合中
        }
    }
    cout << num << endl;
    return 0;
}