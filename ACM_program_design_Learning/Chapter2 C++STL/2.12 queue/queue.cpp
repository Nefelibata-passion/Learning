#include <iostream>
#include <queue>

using namespace std;

//下面的程序详细说明了queue队列的使用方法

int main() {
    //定义队列，元素类型是整型
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(9);
    //返回队列元素数量
    cout << q.size() << endl;
    //队列是否为空，是空，则返回逻辑真，否则返回逻辑假
    cout << q.empty() << endl;
    //读取队首元素
    cout << q.front() << endl;
    //读取队尾元素
    cout << q.back() << endl;
    //所有的元素出列（删除所有元素）
    while(q.empty() != true) {
        cout << q.front() << " ";
        //队首元素出队（删除队首元素）
        q.pop();
    }
    cout << endl;
    return 0;
}