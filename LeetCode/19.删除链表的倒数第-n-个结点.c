/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // // 创建三个指针
    // struct ListNode *fast, *cur, *prev;
    // fast = cur = prev = head;

    // int tmp = n + 1;
    // //int count = 0;
    // // 让前面的指针先走n步
    // while (tmp --)
    // {
    //     // 如果走n步已经走超了
    //     if (fast == NULL/*&& count != n*/)
    //         return NULL;
    //     //count ++;
    //     fast = fast->next;
    //     //cur = cur->next;
    // }

    // cur = head->next;
    // while (fast)
    // {
    //     prev = prev->next;
    //     cur = cur->next;
    //     fast = fast->next;
    // }
    // // 走到这个地方 cur 指向的是倒数第N个节点，prev 指向的是倒数第N个节点的前一个节点
    // prev->next = cur->next;
    // free(cur);
    // return head;
    struct ListNode *fast, *cur;
    fast = cur = head;
    int tmp = n;
    // 让前面的指针先走n步
    while (tmp --)
    {
        // 如果走n步已经走超了
        if (fast == NULL/*&& count != n*/)
            return NULL;
        fast = fast->next;
    }
    struct ListNode *tail = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *newHead = tail;
    while (fast)
    {
        tail->next = cur;
        tail = tail->next;

        cur = cur->next;
        fast = fast->next;
    }
    //struct ListNode *tmp = cur;
    cur = cur->next;
    //free(tmp);
    while (cur)
    {
        tail->next = cur;
        tail = tail->next;
    }
    return newHead->next;
}
// @lc code=end

