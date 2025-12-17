#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


//定义结构体2.13.2
struct Info {
    string name;
    float score;
    //重载"<"操作符，指定优先规则（排序规则）
    bool operator < (const Info &a) const
    {
        //按score由小到大排列，如果要由大到小排列，使用">"即可
        return a.score < score;
    }
};

//重载"()"操作符
struct myComp {
    bool operator () (const int &a, const int &b) {
        //由小到大排列采用">";如果要由大到小排列，则采用"<"
        return a > b;
    }
};

int main() {

    //2.13.1 优先队列的使用方法
    //优先队列包含入队push()（插入元素）、出队pop()（删除元素）、读取队首元素top()、
    //判断队列是否为空empty()和读取队列元素数量size()等方法
    //定优先队列，元素类型为整型
    priority_queue<int> pq1;
    //入队，插入新元素
    pq1.push(1);
    pq1.push(2);
    pq1.push(3);
    pq1.push(9);
    //返回队列中元素数目
    cout << "2.13.1:" << endl;
    cout <<"pq1.size():" << pq1.size() << endl;
    //所有元素出队，删除所有元素
    while(pq1.empty() != true) {
        //读取当前队首元素
        cout << pq1.top() << " ";
        //出队，删除队首元素
        pq1.pop();
    }
    cout << endl;

    //2.13.2 重载“<”操作符来定义优先级
    //如果优先队列的元素类型是结构体，可以通过在结构体重载"<"操作符的方法来修改队列的优先性
    //定义优先队列，元素类型为Info结构体
    priority_queue<Info> pq2;
    //定义结构体变量
    Info info;

    //入队
    info.name = "Jack";
    info.score = 68.5;
    pq2.push(info);

    info.name = "Bomi";
    info.score = 18.5;
    pq2.push(info);

    info.name = "Peti";
    info.score = 90;
    pq2.push(info);

    cout << "2.13.2:" << endl;

    //元素全部出队
    while(pq2.empty() != true) {
        //返回队首元素
        cout << pq2.top().name << ":" << pq2.top().score << endl;
        //出队，删除队首元素
        pq2.pop();
    }


    //2.13.3重载"()"操作符来定义优先级
    //定义优先队列，元素类型为结构体，显示说明内部结构是vector
    priority_queue<int, vector<int>, myComp> pq3;
    //入队
    pq3.push(1);
    pq3.push(9);
    pq3.push(2);
    pq3.push(30);
    //元素全部出队
    cout << "2.14.3:" << endl;
    while(pq3.empty() != true) {
        //返回队首元素
        cout << pq3.top() << " ";
        //出队，删除队首元素
        pq3.pop();
    }
    cout << endl;
    return 0;
}