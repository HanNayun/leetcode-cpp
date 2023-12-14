#pragma once

#include <stack>
#include <string>
#include <vector>

namespace leetcode_22 {
class Solution
{
public:
    static void CreateParenthesis(std::vector<std::string>& res,
                                  std::string str,
                                  const int left,
                                  const int right)
    {
        if (left == 0 && right == 0)
        {
            res.push_back(str);
            return;
        }

        if (left < right)
            CreateParenthesis(res, str + ")", left, right - 1);

        if (left > 0)
            CreateParenthesis(res, str + "(", left - 1, right);
    }

    std::vector<std::string> generateParenthesis(int n)
    {
        auto res{std::vector<std::string>{}};
        CreateParenthesis(res, "", n, n);
        return res;
    }
};
}
