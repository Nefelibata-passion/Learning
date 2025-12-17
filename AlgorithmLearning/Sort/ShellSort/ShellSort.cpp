/*
希尔排序：
基本思想
希尔排序是直接插入排序的改进版，也称为“缩小增量排序”。
它将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序。

1.选择一个增量序列d1,d2,...,dk,其中di > di+1,且dk = 1。
2.按增量d将数组分组（下标相差d的为一组），对每组进行直接插入排序
3.随着增量减小，数组逐渐接近有序，最后当d = 1时，进行最后一次直接插入排序（此时效率极高）

复杂度与稳定性：
时间复杂度：依赖于增量序列。
    希尔原稿（N/2，N/4...）：最坏O(N^2)。
    Hibbard增量(2^k - 1)：最坏O(N^1.5)。
    Knuth增量等通常认为在O(N^1.3)左右。
空间复杂度：O(1)。
稳定性：不稳定（因为相同的元素可能被分在不同的组中移动，破坏了相对顺序）。
*/

#include <iostream>
#include <vector>

void shellSort(std::vector<int>& nums) {
    int n = nums.size();

    // 1. 第一层循环：确定增量 gap，每次减半
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 2. 第二层循环：从第 gap 个元素开始，逐个向后遍历
        // 注意：这里 i++，意味着我们在交替处理不同的组
        // 例如 gap=2 时，i=2 处理第一组，i=3 处理第二组，i=4 处理第一组...
        for (int i = gap; i < n; ++i) {
            int key = nums[i];  // 当前待插入的元素
            int j = i - gap;    // 同组的前一个元素下标

            // 3. 第三层循环：组内的直接插入排序
            // 与普通插入排序的区别仅在于：步长是 gap 而不是 1
            while (j >= 0 && nums[j] > key) {
                nums[j + gap] = nums[j];  // 将大的元素向后挪 gap 位
                j -= gap;                 // 继续向前找
            }

            // 找到位置，插入
            nums[j + gap] = key;
        }
    }
}

int main() {
    std::vector<int> arr = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    shellSort(arr);

    for (int x : arr)
        std::cout << x << " ";
    return 0;
}