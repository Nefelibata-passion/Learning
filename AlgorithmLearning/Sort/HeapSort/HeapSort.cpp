/*
堆排序

堆： 是一颗完全二叉树。
小根堆：父结点的值 <= 其子结点的值。
大根堆：父结点的值 >= 其子结点的值。

对节点使用左右孩子编号法：
1.结点i的左孩子是2*i
2.结点i的右孩子是2*i+1
3.结点i的父结点是i/2

堆（完全二叉树）可以用一维数组存储。
*/


//1.堆的插入：把新元素从堆尾插入，再逐层上浮到合适位置
//O(logn)
int a[1000010], cnt;

void up(int u) {  //上浮
    if(u/2 && a[u/2] > a[u]) {
        swap(a[u], a[u/2]);
        up(u/2);
    }
}

void push(int x) {  //压入
    a[++cnt] = x;
    up(cnt);
}


//2.堆的删除：把尾元素移到根上，再逐层下沉到合适位置
//O(logn)
void down(int u) {  //下沉
    int v = u;
    if(u*2 <= cnt && a[u*2] < a[v]) v = u * 2;
    if(u*2+1 <= cnt && a[u*2+1] < a[v]) v = u * 2 + 1;
    if(u != v) {
        swap(a[u], a[v]);
        down(v);
    }
}

void pop() {  //删除
    a[1] = a[cnt--];
    down(1);
}

int main() {
    int n;
    scanf("%d", &n);    //操作次数


    while(n--) {
        int op, x;
        scanf("%d", &op);


        if(op == 1) {
            scanf("%d", &x);
            push(x);
        }
        else if(op == 2)
            printf("%d\n", a[1]);
        else 
            pop();


    }


}

//O(nlogn)



//STL代码
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main() {
    int n;
    scanf("%d", &n);    //操作次数

    
    while(n--) {
        int op, x;
        scanf("%d," &op);


        if(op == 1) {
            scanf("%d", &x);
            q.push(x);
        }
        else if(op == 2)
            printf("%d\n", q.top());
        else 
            q.pop();


    }

    
}