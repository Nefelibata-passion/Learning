/*直接插入排序
基本思想：
将数组分为两个部分：已排序区间和未排序区间。
初始时，已排序区间只有第1个元素。算法从第2个元素开始，将其与已排序区间的元素从后往前比较，
如果当前元素比已排序元素小，就将已排序元素向后移动，直到找到合适的位置插入。

复杂度与稳定性：
时间复杂度：平均O(N^2)，最好O(N)(本来就是有序的)，最坏O(N^2)。
空间复杂度：O(1)。
稳定性：稳定
*/

#include <vector>
#include <iostream>

void directInsertSort(std::vector<int>& nums) {
    int n = nums.size();
    if(n <= 1)
        return;
    
    //从第二个元素开始遍历（下标为1）
    for (int i = 1; i < n; ++i) {
        int key = nums[i];  //待插入的元素
        int j = i - 1;


        //从后往前查找插入位置，同时移动元素
        //如果key小于nums[j]，则nums[i]后移
        while(j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[i];
            j--;
        }

        //插入key到正确位置
        nums[j + 1] = key;
    }
}