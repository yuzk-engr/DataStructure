
#include <iostream>
using namespace std;

// 二分搜索递归代码
int BinarySearch(int arr[], int i, int j, int val)
{
    if (i > j)
        return -1;

    int mid = (i + j) / 2;
    if (arr[mid] == val)
    {
        return mid;
    }
    else if (arr[mid] > val)
    {
        return BinarySearch(arr, i, mid - 1, val);
    }
    else
    {
        return BinarySearch(arr, mid+1, j, val);
    }
}

// 二分搜索非递归实现
int BinarySearch(int arr[], int size, int val)
{
    return BinarySearch(arr, 0, size - 1, val);

    /*int first = 0;
    int last = size - 1;

    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] > val)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }

    return -1;*/
}

