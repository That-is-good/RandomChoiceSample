#include "content.h"

int GetIndex(int w[], int length, int id)
{
    if (length > 64)
    {
        return GetIndexL(w, length, id);
    }
    return GetIndexH(w, length, id);
}

int GetIndexL(int w[], int length, int id) {
    if (id <= w[0])
    {
        return 0;
    }
    int index = 1;
    for (; index < length; ++index)
    {
        if (id > w[index - 1] && id <= w[index])
        {
            break;
        }
    }
    return index;
}

int GetIndexH(int w[], int length, int id) {
    // 边界检查
    if (length <= 0) return -1;  // 或者抛出异常

    // 处理id小于等于第一个元素的情况
    if (id <= w[0]) {
        return 0;
    }

    // 处理id大于最后一个元素的情况（根据需求决定是否处理）
    if (id > w[length - 1]) {
        return length - 1;  // 或者返回 -1 表示超出范围
    }

    // 二分查找
    int left = 0;
    int right = length - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (w[mid] < id) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}