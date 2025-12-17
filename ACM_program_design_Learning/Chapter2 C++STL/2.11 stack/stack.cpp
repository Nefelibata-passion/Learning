#include <iostream>
#include <stack>
using namespace std;
//下面程序对堆栈各种方法的示例
int main() {
    //定义堆栈s，其元素类型是整型
    stack<int> s;
    //元素入栈
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(9);
    //读取栈顶元素
    cout << "top=" << s.top() << endl; 
    //返回堆栈元素数量
    cout << "size=" << s.size() << endl;
    //判断堆栈是否为空
    cout << "empty=" << s.empty() << endl;
    //所有元素出栈（删除所有元素）
    while(s.empty() != true)//堆栈非空
    {
        cout << s.top() << " ";//输出栈顶元素
        s.pop(); //出栈（即删除栈顶元素）
    }
    cout << endl;
    return 0;
}