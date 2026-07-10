#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 链表节点
struct Node
{
	Node(int val = -1) : val_(val), next_(nullptr) 
	{}
	int val_;
	Node* next_;
};

// 链表
class CLink
{
public:
	CLink()
	{
		head_ = new Node();
		tail_ = head_;
	}
	~CLink()
	{
		//Node* cur = head_->next_;
		//while (cur)
		//{
		//	Node* tmp = cur->next_;
		//	delete cur;
		//	cur = tmp;
		//}
		//delete head_;
		//head_ = nullptr;

		Node* cur = head_;
		while (cur)
		{
			head_ = head_->next_; // 最终指向nullptr
			delete cur;
			cur = head_;
		}
	}

public:
	// 尾插
	void InsertTail(int val)
	{
		//// 找到尾节点 (1. 原来的链表没有节点 2. 原来的链表中有节点)
		//Node* p = head_;
		//while (p->next_ != nullptr)
		//{
		//	p = p->next_;
		//}
		//// 创建新节点
		//Node* newNode = new Node(val);
		//// 在末尾插入新节点
		//p->next_ = newNode;

		Node* newNode = new Node(val);
		tail_->next_ = newNode;
		tail_ = newNode;
		++size_;
	}
	// 头插
	void InsertHead(int val)
	{
		// 创建新节点
		Node* newNode = new Node(val);
		// 在链表头部插入新节点
		newNode->next_ = head_->next_;
		head_->next_ = newNode;

		++size_;
	} // 要先调整新节点的地址域，再调整头节点的地址域
	// 删除值为val的节点
	void Erase(int val)
	{
		if (size_ == 0)
			return;

		Node* prev = head_;
		Node* cur = head_->next_;
		while (cur)
		{
			if (cur->val_ == val)
			{
				prev->next_ = cur->next_;
				delete cur;
				return;
			}
			else
			{
				cur = cur->next_;
				prev = prev->next_;
			}
		}
	}
	// 删除所有值为val的节点
	void EraseAll(int val)
	{
		if (0 == size_)
		{
			return;
		}

		Node* prev = head_;
		Node* cur = head_->next_;
		while (cur)
		{
			if (cur->val_ == val)
			{
				prev->next_ = cur->next_;
				delete cur;
				cur = prev->next_;
			}
			else
			{
				prev = prev->next_;
				cur = cur->next_;
			}
		}
	}
	void EraseTail()
	{
		// 因为尾节点已经保存，用一个指针找到倒数第二个节点
		// 如果除了头节点之外只有一个节点
	}
	void EraseHead()
	{

	}

	Node* huanrukou(Node* head1, Node* head2)
	{
		if (!head1 || !head2)
			return nullptr;

		Node* tmp1 = head1, * tmp2 = head2;
		while (tmp1 != tmp2)
		{
			tmp1 = tmp1->next_ ? tmp1->next_ : head2;
			tmp2 = tmp2->next_ ? tmp2->next_ : head1;
		}
		return tmp1;
	}

	// 打印
	void show()
	{
		Node* p = head_->next_;
		while (p) // 需要找尾节点才 (p->next_ != nullptr) 
		{
			cout << p->val_ << " ";
			//if (p->next_)
			//	cout << "->";
			p = p->next_;
		}
		cout << endl;
	}

private:
	Node* head_; // 指向链表头节点的指针
	Node* tail_; // 指向链表尾节点的指针
	int size_;
};


int main()
{
	CLink l;
	srand(time(0));
	for (int i = 0; i < 10; ++i)
	{
		int val = rand() % 100;
		cout << val << " ";
		l.InsertTail(val);
		//l.InsertHead(val);
	}
	cout << endl;
	l.show();

	l.InsertTail(23);
	l.InsertHead(23);
	l.InsertHead(23);
	l.show();
	//l.Erase(23);
	//l.show();
	l.EraseAll(23);
	l.show();
	return 0;
}