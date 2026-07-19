

#include <iostream>
using namespace std;

// 归并过程函数  O(n)
void Merge(int arr[], int l, int m, int r, int* p)
{
	int idx = 0;
	int i = l;
	int j = m + 1;

	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			p[idx++] = arr[i++];
		}
		else
		{
			p[idx++] = arr[j++];
		}
	}

	while (i <= m)
	{
		p[idx++] = arr[i++];
	}

	while (j <= r)
	{
		p[idx++] = arr[j++];
	}

	// 再把合并好的大段有序的结果，拷贝到原始arr数组[l,r]区间内
	for (i = l, j = 0; i <= r; i++, j++)
	{
		arr[i] = p[j];
	}
}

// 归并排序递归接口
void MergeSort(int arr[], int begin, int end, int* p)
{
	// 递归结束的条件
	if (begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2;
	// 先递
	MergeSort(arr, begin, mid, p);
	MergeSort(arr, mid + 1, end, p);
	// 再归并  [begin, mid]  [mid+1, end] 把两个小段有序的序列，合并成大段有序的序列
	Merge(arr, begin, mid, end, p);
}

// 归并排序
void MergeSort(int arr[], int size)
{
	int* p = new int[size];
	MergeSort(arr, 0, size - 1, p);
	delete[]p;
}

