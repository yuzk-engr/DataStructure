#include <stdio.h>

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


int main()
{
	int arr[] = { 1,3,5,7,9,-2,4,6,8,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	InsertSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}