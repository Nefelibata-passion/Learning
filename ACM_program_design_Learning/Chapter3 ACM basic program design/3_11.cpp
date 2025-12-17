//3.11 列出完数
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    //ifstream cin("aaa.txt");
    vector<int> a;
    for(int i = 2; i < 10000; i += 2) {
        int sum = 1;
        for(int j = 2; j <= i / 2; j++) {
            if(i % j == 0) 
                sum += j;
        }
        if(sum == i)
            a.push_back(i);
    }

    int n;
    while(cin >> n) {
        cout << n << ":";
        for(int i = 0; i < a.size(); i++) { //推测完数为偶数，故步长为2
            if(a[i] <= n)
                cout << " " << a[i];
        }
        cout << endl;
    }
    return 0;
}