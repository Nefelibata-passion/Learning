#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//sort()函数的自定义比较函数
bool Comp(const int &a, const int &b){
    if(a != b){
        return a > b; //降序
    }
    else  
        return a > b;
}

int main(){
    //2.2.1创建vector对象
    vector<int> v;
    vector<double> v2(10); //创建10个元素，默认值为0
    vector<double> v3(10 , 8.6); //创建10个元素，每个元素的值为8.6
    vector<int> v4{1,2,3,4,5}; //使用列表初始化
    vector<int> v5(v4); //使用v4初始化v5


    //2.2.2尾部元素扩张
    v.push_back(2);
    v.push_back(7);
    v.push_back(9);

    //2.2.3下标方式访问vector元素
    cout << "v[0] = " << v[0] << endl;
    cout << "v[1] = " << v[1] << endl;
    cout << "v[2] = " << v[2] << endl;

    //2.2.4迭代器方式访问vector元素
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        //输出迭代器上的元素值
        cout << *it << " ";
    }
    cout << endl;


    //2.2.5元素的插入
    //在最前面插入新元素，元素值为8
    v.insert(v.begin(), 8);
    //在第2个元素前插入新元素，元素值为1
    v.insert(v.begin() + 1, 1);
    //在向量末尾追加新元素3
    v.insert(v.end(), 3);
    //定义迭代器变量
    it = v.begin();
    //输出所有元素
    for(; it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;


    //2.2.6元素的删除
    //erase()方法可以删除vector中迭代器所指的一个元素或一段区间中的所有元素
    //clear()方法可以删除vector中所有元素
    //给向量赋值
    for(int i = 0; i < 10; i++){
        v2[i] = i;
    }
    //输出v2的所有元素
    vector<double>::iterator it2;
    cout << "Initial v2 elements:" << endl;
    for(it2 = v2.begin(); it2 != v2.end(); it2++){
        cout << *it2 << " ";
    }
    //删除第3个元素，从0开始计数
    v2.erase(v2.begin()+2);
    //输出删除后的v2的所有元素
    cout << endl;
    cout << "After erase:" << endl;
    for(it2 = v2.begin(); it2 != v2.end(); it2++){
        cout << *it2 << " ";
    }
    cout << endl;
    //删除迭代器第1到第5区间的所有元素，删除索引为1到4的元素，不删除索引为5的元素
    v2.erase(v2.begin() + 1, v2.begin() + 5);
    //输出删除后的v2的所有元素
    cout << "After erase range:" << endl;
    for(it2 = v2.begin(); it2 != v2.end(); it2++){
        cout << *it2 << " ";
    }
    cout << endl;
    //清空v2
    v2.clear();
    cout << v2.size() << " elements in v2 after clear." << endl;

    //2.2.7使用reverse反向排列算法
    //给v4赋值
    for(int i = 0; i < 5; i++){
        v4.push_back(i + 6);
    }
    //输出v4的所有元素
    cout << "v4 elements before reverse:" << endl;
    for(it = v4.begin(); it != v4.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    //使用reverse反向排列算法
    reverse(v4.begin(), v4.end());
    //输出v4的所有元素
    cout << "v4 elements after reverse:" << endl;
    for(it = v4.begin(); it != v4.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //2.2.8使用sort排序算法对向量元素排序
    //默认情况下，sort()函数使用小于运算符对元素进行升序排序
    //给v5赋值
    for(int i = 0; i < 5; i++){
        v5[i] = 10 - i;
    }
    for(int i = 5; i < 10; i++){
        v5.push_back(10 - i);
    }   
    //输出v5的所有元素
    cout << "v5 elements before sort:" << endl;
    for(it = v5.begin(); it != v5.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    //使用sort排序算法
    sort(v5.begin(), v5.end());
    //输出v5的所有元素
    cout << "v5 elements after sort:" << endl;
    for(it = v5.begin(); it != v5.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    //也可以自己定义比较函数来对元素进行排序，然后把这个函数指定给sort()函数，sort()函数会使用这个函数来比较元素的大小
    //例如，下面的函数可以对元素进行降序排序
    //使用自定义比较函数进行排序
    sort(v5.begin(), v5.end(), Comp);
    //输出v5的所有元素
    cout << "v5 elements after custom sort:" << endl;
    for(it = v5.begin(); it != v5.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //2.2.9向量的大小
    //使用size()方法可以获取向量的大小,即元素的个数
    //使用empty()方法可以判断向量是否为空
    cout << "v5 size: " << v5.size() << endl;
    //输出向量是否为空，如果非空，则返回逻辑假，即"false"，否则返回逻辑真，即"true"
    cout << "Is v5 empty? " << (v5.empty() ? "Yes" : "No") << endl;
    v5.clear(); //清空v5
    cout << "v5 size after clear: " << v5.size() << endl;
    cout << "Is v5 empty after clear? " << (v5.empty() ? "Yes" : "No") << endl;

    
    return 0;
}