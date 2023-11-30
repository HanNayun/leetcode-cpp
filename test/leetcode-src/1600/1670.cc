#include "leetcode_src/1600/1670.h"

#include <gtest/gtest.h>

TEST(Test1670, NormalCase)
{
    auto solution{ leetcode_1670::FrontMiddleBackQueue() };

    solution.pushFront(1);
    solution.pushBack(2);
    solution.pushMiddle(3);
    solution.pushMiddle(4);
    EXPECT_EQ(solution.popFront(), 1);
    EXPECT_EQ(solution.popMiddle(), 3);
    EXPECT_EQ(solution.popMiddle(), 4);
    EXPECT_EQ(solution.popBack(), 2);
}
