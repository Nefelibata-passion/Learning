#include <iostream>
#include <string>
#include <set>

using namespace std;

struct myComp{
    bool operator()(const int &a,const int &b) const {
        if(a != b)
            return a > b;
        else
            return a > b; //对于重复元素，返回false，表示不插入
    }
};

struct Info{
    string name;
    float score;
    //重载"<"操作符，自定义排序规则
    bool operator < (const Info &a) const {
        //按score由大到小排列。如果要由大到小排列，只需把"<"改成">"即可
        return a.score < score;
    }
};

int main(){
    //2.4.1 创建set对象
    //创建set对象时，需要指定元素类型
    //定义元素类型为int的集合对象s，当前没有任何元素
    //元素的排列采用默认的比较规则，当然，可以自定义比较规则函数
    set<int> s1;

    //2.4.2 元素的插入与中序遍历
    //采用insert()方法把元素插入到集合中去，插入的具体规则在默认的比较规则下，是按元素值由小到大插入，如果自己指定了比较规则函数，则按自定义的规则插入
    //使用前向迭代器对集合中序遍历，其结果正好是元素排序的结果
    //定义元素类型为int的集合对象s2，当前没有任何元素
    set<int> s2;
    //插入5个元素，但由于8有重复，第二次插入的8没有执行
    s2.insert(8);   //第1次插入8，可以插入
    s2.insert(1);
    s2.insert(12);
    s2.insert(6);
    s2.insert(8);   //第二次插入8，重复元素，不会插入
    //中序遍历集合中的元素
    set<int>::iterator it2; //定义前向迭代器
    //中序遍历集合中的所有元素
    for(it2 = s2.begin(); it2 != s2.end(); it2++){
        cout << *it2 << " "; // 输出: 1 6 8 12
    }
    cout << endl;


    //2.4.3 元素的反向遍历
    //使用反向迭代器reverse_iterator可以反向遍历集合，输出结果正好是集合元素的反向排序结果。它需要用到rbegin()和rend()方法,它们分别给出了反向遍历的开始位置和结束位置
    set<int>::reverse_iterator rit3; //定义反向迭代器
    for(rit3 = s2.rbegin(); rit3 != s2.rend(); rit3++){
        cout << *rit3 << " "; // 输出: 12 8 6 1
    }
    cout << endl;

    //2.4.4 元素的删除
    //删除的对象可以是某个迭代器位置上的元素、等于某键值的元素、一个区间上的元素和清空集合
    s2.erase(6); //删除键值为6的元素
    //反向遍历集合中的元素
    for(rit3 = s2.rbegin(); rit3 != s2.rend(); rit3++){
        cout << *rit3 << " "; // 输出: 12 8 1
    }
    //清空集合
    s2.clear();
    //输出集合的大小，为0
    cout << s2.size() << endl; // 输出: 0

    //2.4.5 元素的检索
    //使用find()方法对集合进行搜索，如果找到查找的键值，则返回该键值的迭代器位置，否则，返回集合最后一个元素后面的一个位置，即end()
    s2.insert(8);
    s2.insert(1);
    s2.insert(12);
    s2.insert(6);
    s2.insert(8);
    set<int>::iterator it5;
    it5 = s2.find(6); // 查找键值为6的元素
    if(it5 != s2.end())
        cout << "Found: " << *it5 << endl; // 输出: Found: 6
    else
        cout << "Not Found!" << endl;
    it5 = s2.find(20); // 查找键值为20的元素
    if(it5 != s2.end())
        cout << "Found: " << *it5 << endl;
    else
        cout << "Not Found!" << endl; // 输出: Not Found!

    //2.4.6 自定义比较函数
    //使用insert()将元素插入到集合中去的时候，集合会根据设定的比较函数将该元素放到该放的节点上去。
    //在定义集合的时候，如果没有指定比较函数，则采用默认的“<”操作符进行比较，从而实现按元素值由小到大排序。
    //如果自己指定了比较函数，则按自定义的规则插入
    //(1) 如果元素不是结构体，那么，可以编写比较函数。
    set<int,myComp> s6;
    s6.insert(8);
    s6.insert(1);
    s6.insert(12);
    s6.insert(6);
    s6.insert(8);
    set<int,myComp>::iterator it6; //定义前向迭代器
    for(it6 = s6.begin(); it6 != s6.end(); it6++){
        cout << *it6 << " "; // 输出: 12 8 6 1
    }
    cout << endl;
    //(2) 如果元素是结构体，那么，可以直接把比较函数写在结构体内。
    set<Info> s6_2;
    Info info;
    //插入3个元素
    info.name = "Jack";
    info.score = 80.5;
    s6_2.insert(info);
    info.name = "Tomi";
    info.score = 20.5;
    s6_2.insert(info);
    info.name = "Nacy";
    info.score = 60.5;
    s6_2.insert(info);
    set<Info>::iterator it6_2; //定义前向迭代器
    for(it6_2 = s6_2.begin(); it6_2 != s6_2.end(); it6_2++){
        cout << it6_2->name << " : " << it6_2->score << endl;
    }
    return 0;
}