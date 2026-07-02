/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start
int removeElement(int* nums, int numsSize, int val) {
    int *l = nums, *r = nums + numsSize - 1;
    while (l <= r)
    {
        if (*r == val)
        {
            r --;
            continue;
        }
        if (*l == val)
        {
            *l = *r;
            r --;
        }
        else
        {
            l ++;
        }
    }
    return l - nums;
}
// @lc code=end

