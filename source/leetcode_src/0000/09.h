#pragma once

namespace leetcode_09
{
    class Solution
    {
    public:
        bool isPalindrome(int x)
        {
            if (x < 0) return false;
            if (x % 10 == 0 && x != 0) return false;

            auto reverse{0};
            while (x > reverse)
            {
                reverse = reverse * 10 + x % 10;
                x /= 10;
            }

            return reverse == x || x == reverse / 10;
        }
    };
}
