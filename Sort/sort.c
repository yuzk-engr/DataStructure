#include <stdio.h>

// 插入排序
void InsertSort(int* nums, int n)
{
	if (nums == NULL || n == 1)
		return;

	// 首元素默认有序
	for (int i = 1; i <= n - 1; ++i)
	{
		// 本趟要比较的元素
		int tmp = nums[i];
		// 本趟元素的前一个元素
		int j = i - 1;
		// 寻找合适插入位置
		while (j >= 0 && tmp < nums[j])
		{
			nums[j + 1] = nums[j];
			j--;
		}
		// 插入元素
		nums[j + 1] = tmp;
	}
}

void InsertSort2(int* nums, int n)
{
	if (nums == NULL || n == 1)
		return;

	// 首元素默认有序
	for (int i = 1; i <= n - 1; ++i)
	{
		// 本趟要比较的元素
		int tmp = nums[i];
		// 寻找合适插入位置
		int low = 0, high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] > tmp)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		// 移动元素
		for (int j = i - 1; j >= high + 1; j--)
		{
			nums[j + 1] = nums[j];
		}
		// 插入元素
		nums[high + 1] = tmp;
	}
}

void ShellSort(int* nums, int n)
{

}


// 交换排序
void BubbleSort(int* nums, int n)
{
	if (nums == NULL || n <= 1)
		return;

	// n个元素 n - 1趟
	for (int i = 0; i < n - 1; ++i)
	{
		int isexchange = 0;
		for (int j = n - 1; j >= 1 + i; --j)
		{
			if (nums[j] < nums[j - 1])
			{
				int temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
				isexchange = 1;
			}
		}
		if (0 == isexchange)
			return;
	}
}

void QuickSort(int* nums, int begin, int end)
{

}

// 选择排序
// 简单选择排序
// 堆排序

// 归并排序

// 基数排序

int main()
{
	int arr[] = { 1,3,10,7,9,-2,4,6,8,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	BubbleSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}