#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    //2.7.1 multimap对象创建、元素插入
    //multimap对象的创建与map对象一样，只是multimap允许键值重复，
    //插入元素需要使用insert()方法
    //定义map对象，当前没有任何元素
    multimap<string, double> m1;
    //插入元素
    m1.insert(pair<string, double>("Jack", 300.5));
    m1.insert(pair<string, double>("Kity", 200));
    m1.insert(pair<string, double>("Memi", 500));
    //重复插入键值“Jack”
    m1.insert(pair<string, double>("Jack",306));
    //使用前向迭代器中序遍历multimap
    multimap<string, double>::iterator it1;
    cout << "2.7.1" << endl;
    for(it1 = m1.begin(); it1 != m1.end(); it1++){
        //输出键值与映照数据
        cout << (*it1).first << ":" << (*it1).second << endl;
    }

    //2.7.2 元素的删除
    //删除操作采用erase()方法，可删除某个迭代器位置上的元素、等于某个键值的所有重复元素、
    //一个迭代器区间上的所有元素，也可使用clear()方法清空 multimap 容器中的元素清空
    //因为有重复的键值，所以，删除操作会将要删除的键值一次性从multimap中删除
    multimap<string, double> m2;
    m2.insert(pair<string, double>("Jack", 300.5));
    m2.insert(pair<string, double>("Kity", 200));
    m2.insert(pair<string, double>("Memi", 500));
    //重复插入键值“Jack”
    m2.insert(pair<string, double>("Jack",306));
    //使用前向迭代器中序遍历multimap
    multimap<string, double>::iterator it2;
    cout << "2.7.2(1)" << endl;
    for(it2 = m2.begin(); it2 != m2.end(); it2++){
        //输出键值与映照数据
        cout << (*it2).first << ":" << (*it2).second << endl;
    }
    //删除键值为"Jack"的所有元素
    m2.erase("Jack");
    cout << "2.7.2(2)" << endl;
    cout << "the elements after deleted:" << endl;
    for(it2 = m2.begin(); it2 != m2.end(); it2++){
        //输出键值与映照数据
        cout << (*it2).first << ":" << (*it2).second << endl;
    }

    //2.7.3 元素的查找
    //由于multimap存在重复的键值，所以find()方法只返回重复键值中的第一个元素的迭代器位置
    //如果没有找到该键值，则返回end()迭代器位置
    multimap<string, double> m3;
    m3.insert(pair<string, double>("Jack", 300.5));
    m3.insert(pair<string, double>("Kity", 200));
    m3.insert(pair<string, double>("Memi", 500));
    //重复插入键值“Jack”
    m3.insert(pair<string, double>("Jack",306));
    //使用前向迭代器中序遍历multimap
    multimap<string, double>::iterator it3;
    cout << "2.7.3(1)" << endl;
    cout << "all of the elements:" << endl;
    for(it3 = m3.begin(); it3 != m3.end(); it3++){
        //输出键值与映照数据
        cout << (*it3).first << ":" << (*it3).second << endl;
    }
    //查找键值为"Jack"的元素
    cout << "2.7.3(2)" << endl;
    cout <<"the searching result:" << endl;
    it3 = m3.find("Jack");
    if(it3 != m3.end()){
        cout << (*it3).first << ":" << (*it3).second << endl;
    }else{
        cout << "Not Found!" << endl;
    }
    it3 = m3.find("Nacy");
    if(it3 != m3.end()){
        cout << (*it3).first << ":" << (*it3).second << endl;
    }else{
        cout << "Not Found!" << endl;
    }
    return 0;
}