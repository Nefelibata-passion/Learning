#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){

    //2.9.1 创建list对象
    //（1）创建空列表
    list<int> lst1_1;
    //（2）创建具有n个元素的链表
    list<int> lst1_2(10);
    //(3）创建具有n个元素且每个元素值为val的链表
    list<int> lst1_3(10, 5);

    //2.9.2 元素插入和遍历：3种方法
    //（1）使用push_back()方法往尾部插入新元素，链表自动扩张
    //（2）使用push_front()方法往首部插入新元素，链表自动扩张
    //（3）采用insert()方法往迭代器位置处插入新元素，链表自动扩张。
    //注意，迭代器只能进行"++"和"--"操作，不能进行"+n"或"-n"操作,
    //因为元素的位置并不是物理相连的
    //采用前向迭代器iterator对链表进行遍历

    //定义元素为整数的list对象，当前没有任何元素
    list<int> lst2;
    //在链表尾部插入新元素，链表自动扩张
    lst2.push_back(2);
    lst2.push_back(1);
    lst2.push_back(5);
    //在链表头部插入新元素，链表自动扩张
    lst2.push_front(8);
    //在任意位置插入新元素，链表自动扩张
    list<int>::iterator it2;
    it2 = lst2.begin();
    it2++;
    lst2.insert(it2, 20);
    //使用前向迭代器遍历链表
    cout << "2.9.2: The elements in lst2:" << endl;
    for(it2 = lst2.begin(); it2 != lst2.end(); it2++){
        cout << *it2 << " ";
    }
    cout << endl;

    //2.9.3 反向遍历
    //采用反向迭代器reverse_iterator对链表进行遍历
    list<int> lst3;
    lst3.push_back(2);
    lst3.push_back(1);
    lst3.push_back(5);
    //反向遍历链表
    list<int>::reverse_iterator rit3;
    cout << "2.9.3: The elements in lst3:" << endl;
    for(rit3 = lst3.rbegin(); rit3 != lst3.rend(); rit3++){
        cout << *rit3 << " ";
    }
    cout << endl;

    //2.9.4 删除元素
    //(1) 可以使用remove()方法删除链表中一个元素，值相同的元素都会被删除
    list<int> lst4_1;
    lst4_1.push_back(2);
    lst4_1.push_back(1);
    lst4_1.push_back(5);
    lst4_1.push_back(1);
    //遍历链表
    cout << "2.9.4(1): Before remove, the elements in lst4_1:" << endl;
    list<int>::iterator it4_1;
    for(it4_1 = lst4_1.begin(); it4_1 != lst4_1.end(); it4_1++){
        cout << *it4_1 << " ";
    }
    cout << endl;
    //删除值等于1的所有元素
    lst4_1.remove(1);
    //遍历链表
    cout << "After remove, the elements in lst4_1:" << endl;
    for(it4_1 = lst4_1.begin(); it4_1 != lst4_1.end(); it4_1++){
        cout << *it4_1 << " ";
    }
    cout << endl;

    //(2) 使用pop_front()方法删除链表首元素，
    //使用pop_back()方法删除链表尾元素
    list<int> lst4_2;
    lst4_2.push_back(2);
    lst4_2.push_back(8);
    lst4_2.push_back(1);
    lst4_2.push_back(5);
    lst4_2.push_back(1);
    //遍历链表
    cout << "2.9.4(2): Before pop, the elements in lst4_2:" << endl;
    list<int>::iterator it4_2;
    for(it4_2 = lst4_2.begin(); it4_2 != lst4_2.end(); it4_2++){
        cout << *it4_2 << " ";
    }
    cout << endl;
    //删除首元素
    lst4_2.pop_front();
    //删除尾元素
    lst4_2.pop_back();
    //遍历链表
    cout << "After pop, the elements in lst4_2:" << endl;
    for(it4_2 = lst4_2.begin(); it4_2 != lst4_2.end(); it4_2++){
        cout << *it4_2 << " ";
    }
    cout << endl;

    //(3) 使用erase()方法删除迭代器位置上的元素
    list<int> lst4_3;
    lst4_3.push_back(2);
    lst4_3.push_back(8);
    lst4_3.push_back(1);
    lst4_3.push_back(5);
    lst4_3.push_back(1);
    //遍历链表
    cout << "2.9.4(3): Before erase, the elements in lst4_3:" << endl;
    list<int>::iterator it4_3;
    for(it4_3 = lst4_3.begin(); it4_3 != lst4_3.end(); it4_3++){
        cout << *it4_3 << " ";
    }
    cout << endl;
    //删除第2个元素（从0开始计数）
    it4_3 = lst4_3.begin();
    it4_3++;
    it4_3++;
    lst4_3.erase(it4_3);
    //遍历链表
    cout << "After erase, the elements in lst4_3:" << endl;
    for(it4_3 = lst4_3.begin(); it4_3 != lst4_3.end(); it4_3++){
        cout << *it4_3 << " ";
    }
    cout << endl;
    //(4) 使用clear()方法清空链表
    list<int> lst4_4;
    lst4_4.push_back(2);
    lst4_4.push_back(8);
    lst4_4.push_back(1);
    lst4_4.push_back(5);
    lst4_4.push_back(1);
    //遍历链表
    cout << "2.9.4(4): Before clear, the elements in lst4_4:" << endl;
    list<int>::iterator it4_4;
    for(it4_4 = lst4_4.begin(); it4_4 != lst4_4.end(); it4_4++){
        cout << *it4_4 << " ";
    }
    cout << endl;
    //清空链表
    lst4_4.clear();
    //输出链表元素个数
    cout << "After clear, the size of lst4_4:" << endl;
    cout << lst4_4.size() << endl;

    //2.9.5 元素查找
    //采用find()查找算法可以在链表中查找元素，
    //如果找到该元素，返回的是该元素的迭代器位置；
    //如果没有找到该元素，返回的是end()迭代器位置。
    //注意，find()算法需要包含头文件<algorithm>。
    list<int> lst5;
    lst5.push_back(2);
    lst5.push_back(8);
    lst5.push_back(1);
    lst5.push_back(5);
    lst5.push_back(1);
    //遍历链表
    cout << "2.9.5: The elements in lst5:" << endl;
    list<int>::iterator it5;
    for(it5 = lst5.begin(); it5 != lst5.end(); it5++){
        cout << *it5 << " ";
    }
    cout << endl;
    //采用find()查找算法在链表中查找
    it5 = find(lst5.begin(), lst5.end(), 5);
    if(it5 != lst5.end())//找到
    {
        cout << "find it" << endl;
    }
    else
    {
        cout << "not find it" << endl;
    }
    it5 = find(lst5.begin(), lst5.end(), 10);
    if(it5 != lst5.end())//找到
    {
        cout << "find it" << endl;
    }
    else
    {
        cout << "not find it" << endl;
    }

    //2.9.6 元素排序
    //采用sort()方法可以对链表元素进行升序排列
    list<int> lst6;
    lst6.push_back(2);
    lst6.push_back(8);
    lst6.push_back(1);
    lst6.push_back(5);
    lst6.push_back(1);
    //遍历链表
    cout << "2.9.6: Before sort, the elements in lst6:" << endl;
    list<int>::iterator it6;
    for(it6 = lst6.begin(); it6 != lst6.end(); it6++){
        cout << *it6 << " ";
    }
    cout << endl;
    //使用sort()方法对链表进行排序，是升序排列
    lst6.sort();
    //遍历链表
    cout << "After sort, the elements in lst6:" << endl;
    for(it6 = lst6.begin(); it6 != lst6.end(); it6++){
        cout << *it6 << " ";
    }
    cout << endl;

    //2.9.7 剔除连续重复元素
    //采用unique()方法可以剔除链表中连续重复的元素，
    //使得每个元素只出现一次。
    list<int> lst7;
    lst7.push_back(2);
    lst7.push_back(8);
    lst7.push_back(1);
    lst7.push_back(1);
    lst7.push_back(1);
    lst7.push_back(5);
    lst7.push_back(1);
    //遍历链表
    cout << "2.9.7: Before unique, the elements in lst7:" << endl;
    list<int>::iterator it7;
    for(it7 = lst7.begin(); it7 != lst7.end(); it7++){
        cout << *it7 << " ";
    }
    cout << endl;
    //使用unique()方法剔除链表中连续重复的元素
    lst7.unique();
    //遍历链表
    cout << "After unique, the elements in lst7:" << endl;
    for(it7 = lst7.begin(); it7 != lst7.end(); it7++){
        cout << *it7 << " ";
    }
    cout << endl;


    return 0;
}