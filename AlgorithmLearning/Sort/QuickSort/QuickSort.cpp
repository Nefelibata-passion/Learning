// 快速排序
/*主要利用分治思想，时间复杂度O(nlogn)
1.令指针i,j指向数列的区间外侧，数列的中值记为x。
2.将数列中<=x的数放左段，>=x的数放右段
3.对于左右两段，再递归以上两个过程，直到每段只有一个数，即全部有序
*/
#include <algorithm>
#include <iostream>

using namespace std;

int n, a[100005];

// 原始快排
void quicksort(int l, int r) {
    if (l == r)
        return;
    int i = l - 1, j = r + 1, x = a[(l + r) / 2];
    while (i < j) {
        do
            i++;
        while (a[i] < x);  // 向右找>=x的数
        do
            j--;
        while (a[j] > x);  // 向左找<=x的数
        if (i < j)
            swap(a[i], a[j]);
    }
    quicksort(l, j);
    quicksort(j + 1, r);
}

/*
1.推出while时，i=j 或 i=j+1。
2.稳定性：相同元素的顺序可能会交换，是不稳定的。
*/

/*
1.如果每次选的x，能让左右两段近似等分，会生成一颗有logn层的均衡二叉树，
每层i,j两指针会遍历所有n个元素，时间复杂度为O(nlogn)。
2.如果每次选的x，只能分离出一个元素，会退化成有n层的链，i,j两指针走的
总步数=n+(n-1)+...+1=(n+1)*n/2,时间复杂度退化为O(n^2)。
3.STL已经实现了高效率的快排函数：sort(a, a+n)。
*/

// 第k小数
int n, k, a[100010];

int qnth_element(int l, int r) {
    if (l == r)
        return a[l];
    int i = l - 1, j = r + 1, x = a[(l + r) / 2];
    while (i < j) {
        do
            i++;
        while (a[i] < x);  // 向右找>=x的数
        do
            j--;
        while (a[j] > x);  // 向左找<=x的数
        if (i < j)
            swap(a[i], a[j]);
    }
    if (k <= j)
        return qnth_element(l, j);
    else
        return qnth_element(j + 1, r);
}

/*
每次取一半递归, i,j指针每层走的步数为n, n/2, n/4, ..., 1,
总步数 = n + n/2 + n/4 + ... + 1 = 2*n,
所以时间复杂度为O(n)。
*/