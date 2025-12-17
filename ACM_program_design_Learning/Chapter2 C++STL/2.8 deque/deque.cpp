#include <deque>
#include <iostream>

using namespace std;

int main(){


    //2.8.1 创建deque对象
    //创建deque对象的方法通常有三种
    //(1)创建没有任何元素的deque对象
    deque<int> d;
    deque<float> dd;
    //（2）创建具有n个元素的deque对象
    deque<int> ddd(10);   //创建具有10个整型元素的deque对象ddd
    //（3）创建具有n个元素的deque对象，并赋初值
    deque<int> dddd(10, 8.5);   //创建具有10个整型元素的deque对象dddd，每个元素的值为8.5

    //2.8.2插入元素
    //(1)使用push_back()方法从尾部插入元素，会不断扩张队列
    deque<int> d2_1;
    //从尾部连续插入3个元素
    d2_1.push_back(1);
    d2_1.push_back(2);
    d2_1.push_back(3);
    //以数组方式输出元素
    cout << "2.8.1(1):" << endl;
    cout << d2_1[0] << " " << d2_1[1] << " " << d2_1[2] << endl;
    //(2)从头部插入元素，不会增加新元素，只将原有的元素覆盖
    deque<int> d2_2;
    d2_2.push_back(1);
    d2_2.push_back(2);
    d2_2.push_back(3);
    //从头部插入元素
    d2_2.push_front(10);
    d2_2.push_front(20);
    //以数组方式输出元素
    cout << "2.8.2(2):" << endl;
    cout << d2_2[0] << " " << d2_2[1] << " " << d2_2[2] << endl;
    //（3）从中间插入元素，不会增加新元素，只将原有的元素覆盖
    deque<int> d2_3;
    d2_3.push_back(1);
    d2_3.push_back(2);
    d2_3.push_back(3);
    //从中间插入元素
    d2_3.insert(d2_3.begin() + 1, 88);
    //以数组方式输出元素
    cout << "2.8.2(3):" << endl;
    cout << d2_3[0] << " " << d2_3[1] << " " << d2_3[2] << endl;

    //2.8.3前向遍历
    //（1）以数组方式遍历
    deque<int> d3_1;
    d3_1.push_back(1);
    d3_1.push_back(2);
    d3_1.push_back(3);
    //以数组方式输出元素
    cout << "2.8.3(1):" << endl;
    for (int i = 0; i < d3_1.size(); i++){
        cout << d3_1[i] << " ";
    }
    cout << endl;
    //（2）以前向迭代器方式遍历
    deque<int> d3_2;
    d3_2.push_back(1);
    d3_2.push_back(2);
    d3_2.push_back(3);
    //以前向迭代器方式遍历
    cout << "2.8.3(2):" << endl;
    deque<int>::iterator it3_2;
    for(it3_2 = d3_2.begin(); it3_2 != d3_2.end(); it3_2++){
        cout << *it3_2 << " ";
    }
    cout << endl;
    //2.8.4反向遍历
    deque<int> d4;
    d4.push_back(1);
    d4.push_back(2);
    d4.push_back(3);
    //以反向迭代器方式遍历
    cout << "2.8.4:" << endl;
    deque<int>::reverse_iterator rit4;
    for(rit4 = d4.rbegin(); rit4 != d4.rend(); rit4++){
        cout << *rit4 << " ";
    }
    cout << endl;

    //2.8.5删除元素
    //可以从双端队列容器的首部、尾部、中部删除元素，并可以清空双端队列容器
    //（1）采用pop_front()方法从首部删除元素
    deque<int> d5_1;
    d5_1.push_back(1);
    d5_1.push_back(2);
    d5_1.push_back(3);
    d5_1.push_back(4);
    d5_1.push_back(5);
    //从首部删除元素
    d5_1.pop_front();
    d5_1.pop_front();
    //以前向迭代器方式遍历
    cout << "2.8.5(1):" << endl;
    deque<int>::iterator it5_1;
    for(it5_1 = d5_1.begin(); it5_1 != d5_1.end(); it5_1++){
        cout << *it5_1 << " ";
    }
    cout << endl;
    //（2）采用pop_back()方法从尾部删除元素
    deque<int> d5_2;
    d5_2.push_back(1);
    d5_2.push_back(2);
    d5_2.push_back(3);
    d5_2.push_back(4);
    d5_2.push_back(5);
    //从尾部删除元素
    d5_2.pop_back();
    //以前向迭代器的方式遍历
    cout << "2.8.5(2):" << endl;
    deque<int>::iterator it5_2;
    for(it5_2 = d5_2.begin(); it5_2 != d5_2.end(); it5_2++){
        cout << *it5_2 << " ";
    }
    cout << endl;

    //（3）采用erase()方法从中部删除元素
    deque<int> d5_3;
    d5_3.push_back(1);
    d5_3.push_back(2);
    d5_3.push_back(3);
    d5_3.push_back(4);
    d5_3.push_back(5);
    //从中间删除元素，erase的参数是迭代器位置
    d5_3.erase(d5_3.begin() + 1);
    //以前向迭代器方式遍历
    deque<int>::iterator it5_3;
    cout << "2.8.5(3):" << endl;
    for(it5_3 = d5_3.begin(); it5_3 != d5_3.end(); it5_3++){
        cout << *it5_3 << " ";
    }
    cout << endl;
    //（4）采用clear()方法清空双端队列容器
    deque<int> d5_4;
    d5_4.push_back(1);
    d5_4.push_back(2);
    d5_4.push_back(3);
    d5_4.push_back(4);
    d5_4.push_back(5);
    //清空双端队列容器
    d5_4.clear();
    //输出元素个数
    cout << "2.8.5(4):" << endl;
    cout << d5_4.size() << endl;



    return 0;
}