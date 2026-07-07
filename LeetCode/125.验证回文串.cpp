/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:

    bool isLetterOrNumber(char ch)
    {
        return (
            ch >= '0' && ch <= '9'
        ||  ch >= 'A' && ch <= 'Z'
        ||  ch >= 'a' && ch <= 'z'
        );
    }


    bool isPalindrome(string s) {
        for (auto& e : s)
        {
            if (e >= 'A' && e <= 'Z')
                e += 32;
        }
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isLetterOrNumber(s[left]))
            {
                ++ left;
            }
            while (left < right && !isLetterOrNumber(s[right]))
            {
                -- right;
            }
            if (s[left] != s[right])
                return false;
            else
            {
                ++ left;
                -- right;
            }
        }
        return true;
    }
};
// @lc code=end

