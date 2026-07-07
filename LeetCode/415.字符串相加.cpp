/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:

    // void reverse(string &s)
    // {
    //     int left = 0, right = s.size() - 1;
    //     while (left < right)
    //     {
    //         char ch = s[left];
    //         s[left] = s[right];
    //         s[right] = ch;
    //         ++ left, -- right;
    //     }
    // }
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        //int count = end1 > end2 ? end1 : end2;
        string ret;
        int tmp = 0;
        while (end1 >= 0 || end2 >= 0 || tmp != 0)
        {
            int num = 0;
            if (end1 >= 0)
                num += num1[end1] - '0';
            if (end2 >= 0)
                num += num2[end2] - '0';
            num += tmp;
            tmp = num / 10;
            num = num % 10;

            ret += num + '0';

            --end1, --end2;
        }
        //ret.reverse(ret.begin(), ret.end());
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

