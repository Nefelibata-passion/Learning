#include <iostream>
#include <bitset>
using namespace std;

int main() {

    //2.10.1 创建bitset对象
    //创建bitset对象时，必须要指定容器的大小。
    //bitset对象的大小一经定义，就不能修改了。
    bitset<100000> b1; //创建一个大小为100000的bitset对象，所有位都初始化为0

    //2.10.2 设置元素值
    //（1）采用下标法
    bitset<10> b2_1;
    //采用下标法给元素赋值
    b2_1[1] = 1;
    b2_1[6] = 1;
    b2_1[9] = 1;
    //下标法输出所有元素，第0位是最低位，第9位是最高位
    int i;
    cout << "2.10.2(1):" << endl;
    for(i = b2_1.size() - 1; i >= 0; i--){
        cout << b2_1[i];
    }
    cout << endl;

    //采用set()方法，一次性将元素设置为1
    bitset<10> b2_2;
    b2_2.set(); //将所有位都设置为1
    cout << "2.10.2(2):" << endl;
    for(i = b2_2.size() - 1; i >= 0; i--){
        cout << b2_2[i];
    }
    cout << endl;

    //(3)采用set(pos, value)方法，将某pos位设置为1
    bitset<10> b2_3;
    b2_3.set(1, 1);
    b2_3.set(6, 1);
    b2_3.set(9, 1);
    cout << "2.10.2(3):" << endl;
    for(i = b2_3.size() - 1; i >= 0; i--){
        cout << b2_3[i];
    }
    cout << endl;

    //2.10.3 输出元素
    //（1）采用下标法输出元素
    bitset<10> b3_1;
    b3_1.set();
    b3_1.set(0, 0);
    b3_1.set(2, 0);
    b3_1.set(3, 0);
    b3_1.set(4, 0);
    b3_1.set(5, 0);
    b3_1.set(7, 0);
    b3_1.set(8, 0);
    cout << "2.10.3(1):" << endl;
    for(i = b3_1.size() - 1; i >= 0; i--){
        cout << b3_1[i];
    }
    cout << endl;

    //(2)直接向输出流输出全部元素
    bitset<10> b3_2;
    b3_2.set();
    b3_2.set(0, 0);
    b3_2.set(2, 0);
    b3_2.set(3, 0);
    b3_2.set(4, 0);
    b3_2.set(5, 0);
    b3_2.set(7, 0);
    b3_2.set(8, 0);
    cout << "2.10.3(2):" << endl;
    cout << b3_2 << endl;

    

    return 0;
}