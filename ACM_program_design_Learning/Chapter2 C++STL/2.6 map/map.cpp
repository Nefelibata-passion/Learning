#pragma warning(disable:4996)
#include <map>
#include <iostream>
#include <string>

using namespace std;
//2.6.5(1)自定义比较函数
struct myComp{
    bool operator()(const int &a, const int &b) const {
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

    //2.6.1 map创建、元素插入和遍历访问
    //创建 map 对象，键值与映照数据的类型由自己定义。在没有指定比较函数时，
    //元素的插入位置是按键值由小到大插入到黑白树中去的，这点和 set 一样。
    //定义map对象，当前没有任何元素
    map<string,float> m;
    //插入元素，按键值的由小到大放入黑白树中
    m["Jack"] = 98.5;
    m["Bomi"] = 96.0;
    m["Kate"] = 97.5;
    //前向遍历元素
    map<string, float>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        //输出键值与映照数据
        cout << "2.6.1" << endl;
        cout << (*it).first << ":" << (*it).second << endl;
    }

    //2.6.2 删除元素
    //与 set 容器一样，map 映照容器的 erase()删除元素函数，
    //可以删除某个迭代器位置上的元素、等于某个键值的元素、一个迭代器区间上的所有元素，
    //当然，也可使用 clear()方法清空 map 映照容器。
    //定义map对象，当前没有任何对象
    map<int, char> m2;
    //插入元素,按键值的由小到大放入黑白树中
    m2[25] = 'm';
    m2[28] = 'k';
    m2[10] = 'x';
    m2[30] = 'a';
    //删除键值为28的元素
    m2.erase(28);
    //前向遍历元素
    map<int, char>::iterator it2;
    for(it2 = m2.begin(); it2 != m2.end(); it2++){
        //输出键值与映照数据
        cout << "2.6.2" << endl;
        cout << (*it2).first << ":" << (*it2).second << endl;
    }

    //2.6.3 元素反向遍历
    //可以使用反向迭代器 reverse_iterator 反向遍历 map 照映容器中的数据，
    //它需要 rbegin()方法和 rend()方法指出反向遍历的起始位置和终止位置。
    m2[28] = 'k';
    //反向遍历元素
    map<int, char>::reverse_iterator rit;
    for(rit = m2.rbegin(); rit != m2.rend(); rit++){
        //输出键值与映照数据
        cout << "2.6.3" << endl;
        cout << (*rit).first << ":" << (*rit).second << endl;
    }

    //2.6.4 元素的搜索
    //使用 find()方法来搜索某个键值，如果搜索到了，则返回该键值所在的迭代器位置，
    //否则，返回 end()迭代器位置。由于 map 采用黑白树数据结构来实现，所以搜索速度是极快的。
    it2 = m2.find(28);
    if(it2 != m2.end()){
        cout << "2.6.4" << endl;
        cout << (*it2).first << ":" << (*it2).second << endl;
    }else{
        cout << "Not Found!" << endl;
    }

    //2.6.5 自定义比较元素
    //将元素插入到 map 中去的时候，map 会根据设定的比较函数将该元素放到该放的节点上去。
    //在定义 map 的时候，如果没有指定比较函数，那么采用默认的比较函数，
    //即按键值由小到大的顺序插入元素。
    //在很多情况下，需要自己编写比较函数。
    //编写比较函数与 set 比较函数是一致的，因为它们的内部数据结构都是红黑树。
    //编写方法有两种
    //（1）如果元素不是结构体，那么，可以编写比较函数。
    map<int, char, myComp> m5_1;
    m5_1[25] = 'm';
    m5_1[28] = 'k'; 
    m5_1[10] = 'x';
    m5_1[30] = 'a';
    //前向遍历元素
    map<int, char, myComp>::iterator it5;
    cout << "2.6.5(1)" << endl;
    for(it5 = m5_1.begin(); it5 != m5_1.end(); it5++){
        //输出键值与映照数据
        cout << (*it5).first << ":" << (*it5).second << endl;
    }

    //(2) 如果元素是结构体，那么，可以直接把比较函数写在结构体中。
    map<Info, int> m5_2;
    Info info;
    info.name = "Jack";
    info.score = 60;
    m5_2[info] = 25;
    info.name = "Bomi";
    info.score = 80;
    m5_2[info] = 10;
    info.name = "Peti";
    info.score = 66.5;
    m5_2[info] = 30;
    //使用前向迭代器中序遍历map
    map<Info, int>::iterator it6;
    cout << "2.6.5(2)" << endl;
    for(it6 = m5_2.begin(); it6 != m5_2.end(); it6++){
        cout << (*it6).second << ":";
        cout << ((*it6).first).name  << " " << ((*it6).first).score << endl;
    }

    //2.6.6 用map实现数字分离
    //对数字的各位进行分离，采用取余等数学方法操作是很耗时的，而把数字当作字符串，
    //使用map的映照功能，很方便地实现了数字分离。
    map<char, int> m6;
    //赋值：字符映射数字
    m6['0'] = 0;
    m6['1'] = 1;
    m6['2'] = 2;
    m6['3'] = 3;
    m6['4'] = 4;
    m6['5'] = 5;
    m6['6'] = 6;
    m6['7'] = 7;
    m6['8'] = 8;
    m6['9'] = 9;
    /*上面的10条赋值语句可采用下面这个代码来简化
    for(int j =0; j < 10; j++){
        m7['0' + j] = j;
    }*/
   string sa, sb;
   sa = "6234";
   int i;
   int sum = 0;
   for(i = 0; i < sa.length(); i++){
        sum += m6[sa[i]];
   }
   cout << "2.6.6" << endl;
   cout << "sum=" << sum << endl;

   //2.6.7 数字映照字符的map写法
   map<int, char> m7;
   for(int j = 0; j < 10; j++){
        m7[j] = '0' + j;
   }
   int n = 7;
   string s = "The number is ";
   cout << "2.6.7" << endl;
   cout << s + m7[n] << endl;

    return 0;
}