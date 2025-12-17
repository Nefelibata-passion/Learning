#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){

    //2.5.1 multiset元素的插入
    //定义元素类型为string的多重集合对象ms1，当前为空
    multiset<string> ms1;
    ms1.insert("abc");
    ms1.insert("123");
    ms1.insert("111");
    ms1.insert("aaa");
    ms1.insert("123");
    multiset<string>::iterator it1;
    for(it1 = ms1.begin(); it1 != ms1.end(); it1++){
        cout << *it1 << endl;
    }

    //2.5.2 multiset元素的删除
    //采用erase()方法可以删除multiset对象中的某个迭代器位置上的元素、某段迭代器区间中的元素、键值等于某个值的所有重复元素，并返回删除元素的个数。
    //采用clear()可以清空元素
    //删除值为"123"的所有重复元素，返回删除元素总数2
    int n = ms1.erase("123");
    cout << "Total deleted : " << n << endl;
    //输出和删除后的剩余元素
    cout << "All elements after deleted : " << endl;
    for(it1 = ms1.begin(); it1 != ms1.end(); it1++){
        cout << *it1 << endl;
    }
    ms1.clear();
    //2.5.3 查找元素
    //使用find()方法查找元素，如果找到，则返回该元素的迭代器位置（如果该元素存在重复，则返回第一个元素重复元素的迭代器位置）；
    //如果没有找到，则返回end()迭代器位置
    ms1.insert("abc");
    ms1.insert("123");
    ms1.insert("111");
    ms1.insert("aaa");
    ms1.insert("123");
    multiset<string>::iterator it3;
    //查找键值"123"
    it3 = ms1.find("123");
    if(it3 != ms1.end())//找到
        cout << *it3 << endl;
    else//没有找到
        cout << "not find it" << endl;
    it3 = ms1.find("bbb");
    if(it3 != ms1.end())//找到
        cout << *it3 << endl;
    else//没有找到
        cout << "not find it" << endl;
    return 0;
}