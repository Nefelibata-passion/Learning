/*
折半插入排序：
基本思想
直接插入排序在“查找插入位置”时是线性查找。折半插入排序利用了已排序区间是有序的这一特点，使用**二分查找（Binary
Search）**来确定插入位置。 虽然查找位置的速度变快了（O(logN)），但移动元素的次数并没有减少，因此整体的时间复杂度阶数不变。

复杂性与稳定性：
时间复杂度：平均O(N^2)
        比较次数减少为O(NlogN)。
        移动次数依然是O(N^2)。
空间复杂度：O(1)。
稳定性：稳定
*/

#include <vector>

void binaryInsertionSort(std::vector<int>& nums) {
    int n = nums.size();
    if(n <= 1)
        return;
    for (int i = 1; i < n; ++i) {
        int key = nums[i];

        //在已排序区间[0, i-1]中利用二分查找寻找插入位置
        int low = 0, high = i - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;  //保证稳定性，相等时继续向右找
            }
        }


        //此时low即为应当插入的位置
        //将[low, i-1]的元素整体后移
        for (int j = i - 1; j >= low; --j) {
            nums[j + 1] = nums[j];
        }

        nums[low] = key;
    }
}