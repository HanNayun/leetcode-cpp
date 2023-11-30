#include "leetcode_src/0000/19.h"
#include <gtest/gtest.h>

TEST(Test19, NormalCase)
{
    auto head = CreateList(std::vector<int>{ 1, 2, 3, 4, 5 });
    auto n{ 2 };
    auto solution{ leetcode_19::Solution{} };
    auto result{ solution.removeNthFromEnd(head, n) };
    auto expected{ std::vector<int>{ 1, 2, 3, 5 } };
    EXPECT_EQ(ListToVector(result), expected);

    delete head;

    head = CreateList({ 1 });
    n = 1;
    result = solution.removeNthFromEnd(head, n);
    expected = std::vector<int>{};
    EXPECT_EQ(ListToVector(result), expected);
    delete head;

    head = CreateList({ 1, 2 });
    n = 2;
    result = solution.removeNthFromEnd(head, n);
    expected = std::vector<int>{ 2 };
    EXPECT_EQ(ListToVector(result), expected);
}
