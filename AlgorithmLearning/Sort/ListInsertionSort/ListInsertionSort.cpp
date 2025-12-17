/*
表插入排序：
基本思想：
直接插入排序需要大量移动元素。表插入排序为了减少移动次数，使用静态链表（数组+游标/指针）来存储数据。
不移动记录：在排序过程中，不物理移动数据，只修改元素的next指针（游标），将它们逻辑上连接成有序链表。
重排（可选）：如果需要物理有序，可以在排序结束后根据链表顺序重排数组。
结构定义：
通常使用一个结构体数组，包含 data（数据）和next（下一个元素的下标）。
为了方便，通常将数组的下标0作为“头结点/哨兵”，不存实际数据，或者作为最大值哨兵。

复杂度与稳定性：
时间复杂度：O(N^2)（虽然不移动数据，但比较次数还是O(N^2)）。
空间复杂度：O(N)（需要额外的next数组）。
稳定性：稳定
*/

#include <vector>
#include <iostream>

struct Element {
    int data;
    int next;       //游标，指向下一个元素的数组下标
};

void listInsertionSort(std::vector<int>& rawData) {
    int n = rawData.size();
    //0号位置作为头结点，不存实际排序数据
    std::vector<Element> tbl(n + 1);

    //初始化数据，data从1开始存，next初始化为0
    for (int i = 0; i < n; ++i) {
        tbl[i + 1].data = rawData[i];
        tbl[i + 1].next = 0;
    }

    tbl[0].next = 1;        //头结点指向第1个元素（初始已排序链表只有第1个元素）
    tbl[0].data = -2147483648;   //哨兵最小值（可选）
    tbl[1].next = 0;    //第1个元素的next为0（表示链表结束）

    //从第2个元素开始插入
    for (int i = 2; i <= n; ++i) {
        int key = tbl[i].data;
        int pre = 0;    //从头结点开始找

        //寻找插入位置：找到一个位置pre，使得tbl[pre].data <= key < tbl[tbl[pre].next].data
        //tbl[pre].next == 0 表示到了链表尾部
        while(tbl[pre].next != 0 && tbl[tbl[pre].next].data < key) {
            pre = tbl[pre].next;
        }

        //插入操作：修改指针
        tbl[i].next = tbl[pre].next;
        tbl[pre].next = i;
    }

    // ---若需输出排序结果---
    std::cout << "List Sort Result:";
    int p = tbl[0].next;
    while(p != 0) {
        std::cout << tbl[p].data << " ";
        p = tbl[p].next;
    }
    std::cout << std::endl;

    //注意：此时物理数组tbl的顺序并未改变，只是next指针构成了逻辑顺序。
    //如果需要物理重排，需要顺着链表仅进行一次O(N)的数据置换。
}