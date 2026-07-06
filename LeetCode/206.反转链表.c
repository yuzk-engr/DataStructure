/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    // 如果链表为空或者链表中只有一个节点则直接返回链表
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *newHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    newHead->val = -1;
    newHead->next = NULL;
    struct ListNode *cur = head;
    while (cur)
    {
        struct ListNode *nextNode = cur->next; // 当前节点的下一个节点
        cur->next = newHead->next;
        newHead->next = cur;
        // 先处理新节点
        cur = nextNode;
    }
    struct ListNode *newList = newHead->next;
    free(newHead);
    return newList;
}
// @lc code=end

