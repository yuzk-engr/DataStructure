#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#if 0

// 数组实现 不考虑泛型
class Array
{
public:
	Array(int size = 16) : mCap(size), mCur(0)
	{
		mpArr = new int[mCap](); // 堆上开辟空间并初始化元素为 int类型 的默认值0
	}
	~Array()
	{
		delete[]mpArr;
		mpArr = nullptr;
	}

public:
	// 尾部插入元素
	void push_back(int val)
	{
		// 判断数组是否已满
		if (mCap == mCur)
		{
			expend(2 * mCap);
		}
		// 插入元素
		mpArr[mCur++] = val;
	}
	// 尾部删除元素
	void pop_back()
	{
		// 判断数组是否为空
		if (0 == mCur)
		{
			return;
		}
		// 删除元素
		mCur--;
	}
	// 在pos位置插入元素
	void insert(int pos, int val)
	{
		// 判断位置合法性
		if (pos < 0 || pos > mCur)
		{
			return; // throw "pos invalid!";
		}
		// 判断数组是否已满
		if (mCur == mCap)
		{
			expend(2 * mCap);
		}
		// 移动元素
		for (int i = mCur - 1; i >= pos; --i)
		{
			mpArr[i + 1] = mpArr[i];
		}
		// 插入元素
		mpArr[pos] = val;
		mCur++;
	}
	// 元素查询 返回下标
	int find(int val)
	{
		for (int i = 0; i < mCur; ++i)
		{
			if (mpArr[i] == val)
				return i;
		}
		return -1;
	}
	// 按位置删除
	void erase(int pos)
	{
		// 判断位置合法性
		if (pos < 0 || pos >= mCur)
		{
			return;
		}
		// 删除元素
		for (int i = pos + 1; i < mCur; ++i)
		{
			mpArr[i - 1] = mpArr[i];
		}
		mCur--;
	}
	void show()
	{
		for (int i = 0; i < mCur; ++i)
		{
			cout << mpArr[i] << " ";
		}
		cout << endl;
	}

private:
	// 数组扩容接口
	void expend(int size)
	{
		// 开辟新空间
		int* p = new int[size]();
		// 拷贝元素
		memcpy(p, mpArr, sizeof(int) * mCur);
		// 释放旧空间
		delete[]mpArr;
		// 修改数组参数
		mpArr = p;
		mCap = size;
	}

private:
	int* mpArr; // 指向堆上数组的指针
	int mCap;   // 数组的容量
	int mCur;   // 数组的元素个数
};


int main()
{
	Array arr(10);
	srand(time(0));
	for (int i = 0; i < 10; ++i)
	{
		arr.push_back(rand() % 100);
	}
	arr.show();
	arr.pop_back();
	arr.show();
	arr.insert(0, 200);
	arr.show();
	arr.insert(10, 10086);
	arr.show();
	arr.erase(arr.find(200));
	arr.show();
}



#include <iostream>
#include <cstring>
using namespace std;
// 反转字符串
void Reverse(char* str, int size)
{
	if (!str || !size)
		return;

	int left = 0, right = size - 1;
	while (left < right)
	{
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;

		++left, --right;
	}

	char* l = str, * r = str + size - 1;
	while (l < r)
	{
		char tmp = *l;
		*l = *r;
		*r = tmp;

		++l, --r;
	}
}

int main()
{
	char str[] = "hello world~";
	Reverse(str, strlen(str));
	cout << str << endl;
}

#endif


// 整数数组，把偶数调整到数组的左边，把奇数调整到数组的右边

//void AdjustArray(int* arr, int size)
//{
//	int* l = arr, * r = arr + size - 1;
//	while (l < r)
//	{
//		// 从前向后找奇数
//		while (l < r)
//		{
//			if ((*l & 0x1) == 1)
//			{
//				break;
//			}
//			l++;
//		}
//		// 从后向前找偶数
//		while (l < r)
//		{
//			if ((*r & 0x1) == 0)
//			{
//				break;
//			}
//			r--;
//		}
//		if (l < r)
//		{
//			int tmp = *l;
//			*l = *r;
//			*r = tmp;
//		}
//	}
//}

void AdjustArray(int* arr, int size)
{
	int* l = arr, * r = arr + size - 1;
	while (l < r)
	{
		// 从后向前找偶数
		if ((*r & 0x1) == 1)
		{
			r--;
			continue;
		}
		// 从前先后找奇数
		if ((*l & 0x1) == 0)
		{
			l++;
			continue;
		}
		int tmp = *l;
		*l = *r;
		*r = tmp;
	}
}

int main()
{
	srand(time(0));
	int arr[10];
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = rand() % 100;
	}
	for (int e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	AdjustArray(arr, sizeof(arr) / sizeof(arr[0]));
	for (int e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
