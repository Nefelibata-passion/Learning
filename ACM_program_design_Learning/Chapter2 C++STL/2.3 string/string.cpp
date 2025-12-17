#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    //2.3.1 创建string对象
    string s;
    cout << s.length() << endl; // 输出0，表示空字符串

    //2.3.2 给string对象赋值
    //(1)直接给字符串对象赋值
    s = "Hello, C++ STL!";
    cout << s << endl; // 输出: Hello, C++ STL!

    //(2) 更常用的方法是， 把字符指针赋值给一个字符串对象
    char ss[5000];
    //scanf的输入速度比cin快得多
    //scanf是c语言的函数，不支持string对象
    scanf("%s", ss);
    s = ss; // 将字符数组赋值给字符串对象
    cout << s << endl; // 输出输入的字符串
    //运行结果：
    //先从键盘输入"hello,string."
    //输出："hello,string."

    //2.3.3 从string对象尾部添加字符
    //在string对象的尾部添加一个字符(char),采用“+”操作符即可
    string s1;
    s1 = s1 + 'a';
    s1 = s1 + 'b';
    s1 += 'c';
    cout << s1 << endl; // 输出: abc

    //2.3.4 从string对象尾部追加字符串
    //(1)直接采用“+”操作符
    string s2;
    s2 = s2 + "abc";
    s2 += "123";
    cout << s2 << endl; // 输出: abc123
    //(2)使用append函数
    string s3;
    s3.append("abc");
    s3.append("123");
    cout << s3 << endl; // 输出: abc123

    //2.3.5 给string对象插入字符
    //可以用insert()方法把一个字符插入到迭代器位置之前
    string s4;
    s4 = "123456";
    //定义迭代器
    string::iterator it = s4.begin();
    //把字符'p'插入到第1个字符前(注意，字符位置从0开始计数)
    s4.insert(it + 1, 'p');
    cout << s4 << endl; // 输出: 1p23456

    //2.3.6 访问string对象的元素
    string s6;
    s6 = "abc123456";
    cout << s6[0] << endl; // 输出: a
    cout << s6[0] - 'a' << endl; // 输出: 0


    //2.3.7 删除string对象的元素
    string s7;
    //(1) 清空一个字符串，则直接给它赋空字符串
    //(2)使用erase()方法删除迭代器所指的那个元素或一个区间中的区间元素
    s7 = "abc123456";
    string::iterator it7 = s7.begin();
    //删除第3个元素，元素位置从0开始计数
    s7.erase(it7 + 3);
    cout << s7 << endl; // 输出: abc23456
    //删除0~4区间的所有元素
    s7.erase(it7, it7 + 4);
    cout << s7 << endl; // 输出: 3456
    //清空字符串
    s7 = "";
    cout << s7.length() << endl; // 输出: 0


    //2.3.8 返回string对象的长度
    string s8;
    s8 = "abc123456";
    cout << s8.length() << endl; // 输出: 9
    s8 = "";
    cout << s8.empty() << endl; // 输出: 1，表示字符串为空


    //2.3.9 替换string对象的字符
    string s9;
    //使用replace()方法可以很方便地替换string对象中的字符，replace()方法的重载函数相当多，常用的只有一两个
    s9 = "abc123456";
    //从第3个开始，将连续的3个字符替换为"good"
    s9.replace(3, 3, "good");
    cout << s9 << endl; // 输出: abcgood456


    //2.3.10 搜索string对象的元素或子串
    //采用find()方法可查到字符串中的第一个字符元素(char,用单引号界定)或子串(用双引号界定)，如果查到，则返回下标值（从0开始计数），如果查不到，则返回4294967295(32位系统)  
    //18446744073709551615(64位系统)   string::npos
    //在 32 位系统 上，size_t 通常是 unsigned int（32 位无符号整数），其最大值是 2^32 - 1 = 4294967295。
    //因此，std::string::npos 在 32 位系统上通常是 4294967295。
    //在 64 位系统 上，size_t 是 unsigned long long（64 位），此时 npos 的值是 18446744073709551615（即 2^64 - 1）。
    string s10;
    s10 = "cat dog cat";
    //查找第一个字符'c',返回下标值
    cout << s10.find('c') << endl; // 输出: 0
    //查找第一个子串"c",返回下标值
    cout << s10.find("c") << endl; // 输出: 0
    //查找第一个子串"cat",返回下标值
    cout << s10.find("cat") << endl; // 输出: 0
    //查找第一个子串"dog",返回下标值
    cout << s10.find("dog") << endl; // 输出: 4
    //查找第一个子串"dogc",查不到则返回4294967295(32位系统)
    cout << s10.find("dogc") << endl; // 输出: 4294967295

    //2.3.11 string对象的比较
    string s11;
    s11 = "cat dog cat";
    //s11比"cat"字符串大，返回1
    cout << s11.compare("cat") << endl; // 输出: 8
    cout << s11.compare("cap") << endl; // 输出: 1
    //实际上，compare() 方法返回的是两个字符串第一个不匹配字符的 ASCII 码差值，
    //如果长度不同且短字符串是长字符串的前缀（如本例），则返回长度差（11-3=8）。但某些实现可能简化返回值为 1 表示大于。
    //不过经过实际测试（在大多数标准库实现中），这段代码确实会输出 1，表示调用字符串大于参数字符串。
    //s11比"cat dog cat"字符串相等，返回0
    cout << s11.compare("cat dog cat") << endl; // 输出: 0
    //s11比"dog"小，返回-1
    cout << s11.compare("dog") << endl; // 输出: -1

    //2.3.12 用reverse()反向排序string对象
    //采用reverse()方法可将string对象迭代器所指向的一段区间中的元素（字符）反向排序。reverse()方法的需要声明头文件"#include <algorithm>"
    string s12;
    s12 = "123456789";
    reverse(s12.begin(),s12.end());
    cout << s12 << endl; // 输出: 987654321

    //2.3.13 string对象作为vector元素
    //string对象可以作为vector向量的元素，这种用法，类似于字符串数组。
    vector<string> v;
    v.push_back("Jack");
    v.push_back("Mike");
    v.push_back("Tom");
    cout << v[0] << endl; // 输出: Jack
    cout << v[1] << endl; // 输出: Mike
    cout << v[2] << endl; // 输出: Tom
    cout << v[0][0] << endl; // 输出: J
    cout << v[1][0] << endl; // 输出: M
    cout << v[2][0] << endl; // 输出: T

    //2.3.14 string类型的数字化处理
    string s14;
    s14 = "1234059";
    int i;
    int sum = 0;
    for(i=0; i < s14.length(); i++){
        if(s14[i] == '0') sum += 0;
        else if(s14[i] == '1') sum += 1;
        else if(s14[i] == '2') sum += 2;
        else if(s14[i] == '3') sum += 3;
        else if(s14[i] == '4') sum += 4;
        else if(s14[i] == '5') sum += 5;
        else if(s14[i] == '6') sum += 6;
        else if(s14[i] == '7') sum += 7;
        else if(s14[i] == '8') sum += 8;
        else if(s14[i] == '9') sum += 9;
    }
    cout << sum << endl; // 输出: 24

    //2.3.15 string对象与字符数组互操作
    string s15;
    char sss[100];
    //输入字符串到字符数组中
    scanf("%s",sss); //输入:"abc123"
    //字符数组赋值线字符串对象
    s15 = sss;
    //用printf输出字符串对象，要采用c_str()方法
    printf(s15.c_str()); //输出:"abc123"
    //换行
    cout << endl;
    //用printf输出字符数组
    printf("%s",sss); //输出:"abc123"
    //换行
    cout << endl;
    //用cout输出字符串对象
    cout << s15 << endl; //输出:"abc123"
    //用cout输出字符数组
    cout << sss << endl; //输出:"abc123"

    //2.3.16 string对象与sscanf()函数
    //待定，不建议，在C++中不推荐使用sscanf()函数来处理字符串，因为它不支持string对象，且容易出错。
    //在C++课设编写过程中，sscanf()出错较多

    string s16_1, s16_2, s16_3;
    char sa[100],sb[100],sc[100];
    //将字符串分离成子串，分隔符为空格
    sscanf("abc 123 pc", "%s %s %s", sa, sb, sc);
    s16_1 = sa; // 将字符数组赋值给字符串对象
    s16_2 = sb; // 将字符数组赋值给字符串对象   
    s16_3 = sc; // 将字符数组赋值给字符串对象
    cout << s16_1 << " " << s16_2 << " " << s16_3 << endl; // 输出: abc 123 pc
    //将字符串分离成数字，分隔符为空格
    int a, b, c;
    sscanf("1 2 3", "%d %d %d", &a, &b, &c);
    cout << a << " " << b << " " << c << endl; // 输出: 1 2 3
    //将字符串分离成数字，分隔符为","和"$"
    //当用到数字的时候，跟scanf一样，它要传指针地址
    int x, y, z;
    sscanf("4,5$6", "%d,%d$%d", &x, &y, &z);
    cout << x << " " << y << " " << z << endl; // 输出: 4 5 6

    //2.3.17 string对象与数值相互转换
    //string对象与数值相互转换，C++11开始支持，C++17也支持
    //string对象转数值
    string s17 = "12345";
    int num = stoi(s17); // 将字符串转换为整数
    cout << num << endl; // 输出: 12345
    //数值转string对象
    int num2 = 67890;
    string s17_2 = to_string(num2); // 将整数转换为字符串
    cout << s17_2 << endl; // 输出: 67890
    //string对象转浮点数
    string s17_3 = "123.456";
    double num3 = stod(s17_3); // 将字符串转换为浮点数
    cout << num3 << endl; // 输出: 123.456
    //浮点数转string对象
    double num4 = 789.012;
    string s17_4 = to_string(num4); // 将浮点数转换为字符串
    cout << s17_4 << endl; // 输出: 789.012


    //第二种方法
/*#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string convertToString(double x){
    ostringstream o;
    if(o << x)
        return o.str();
    return "conversion error";
}

double convertFromString(const string &s){
    istringstream i(s);
    double x;
    if(i >> x)
        return x;
    return 0.0;
}

int main(){
    char b[10];
    string a;
    sprintf(b,"%d",1975);
    a = b;
    cout << a << endl;

    string cc = convertToString(1976);
    cout << cc << endl; 

    string dd = "2006";
    int p = convertFromString(dd)+2;
    cout << p << endl;
    return 0;
}*/
    return 0;
}


