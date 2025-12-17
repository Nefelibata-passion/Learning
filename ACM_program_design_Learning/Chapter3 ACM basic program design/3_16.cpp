//3.16 按绩点排名
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>  //cout的输出格式

using namespace std;

struct student {
    string s;
    double d;
};

//编写比较函数
bool myComp(const student &s1, const student &s2) {
    if(s1.d != s2.d)
        return s1.d > s2.d;  //由大到小则使用“>”
    if(s1.s != s2.s)
        return s1.s < s2.s;  //由小到大则使用“<”
}

int main() {
    //ifstream cin("aaa.txt");
    int n;      //班级数量
    int c;      //课程数量
    double xf;  //学分
    vector<double> vxf;   //学分向量
    int p;      //班级人数
    string name;  //学生名称
    double score;  //成绩
    student xs;   //学生名称与总学分结构体
    vector<student> vxs;  //最终学生名称与总学分
    cin >> n;  //n个班
    for(int i = 0; i < n; i++) {//处理每一个班
        cin >> c;  //读入课程数量
        for(int j = 0; j < c; j++) {//读入每门课程的学分
            cin >> xf;
            vxf.push_back(xf);    
        }
        cin >> p;  //读入班级人数
        //读入一个班的p个学生的名称与每门课成绩
        for(int k = 0; k < p; k++) {
            cin >> name;   //读入学生名称
            xs.s = name;
            xf = 0.0;
            for(int m = 0; m < c; m++) {//读入每门课程的分数
                cin >> score;
                //成绩要大于等于60分才计算绩点
                if(score < 60)
                    continue;
                xf = xf + (score -50)/10 *vxf[m];  //计算总学分
            }
            xs.d = xf/10;
            vxs.push_back(xs);
        }
        //输出每个班的情况
        cout << (i ? "\n" : "");
        cout << "class " << i+1 << ":" << endl;
        sort(vxs.begin(), vxs.end(), myComp);   //带自定义比较函数myComp
        for(vector<student>::iterator it = vxs.begin(); it < vxs.end(); it++) {
            cout << fixed << setprecision(2);
            cout << left << setw(11);
            cout << (*it).s << (*it).d << endl;
        }
        vxf.clear();
        vxs.clear();
    }
    return 0;
}