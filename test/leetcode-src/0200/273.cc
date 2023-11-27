#include "leetcode_src/0200/273.h"
#include <gtest/gtest.h>

TEST(Test273, NormalCase)
{
    auto solution{leetcode_273::Solution()};
    EXPECT_EQ(solution.numberToWords(123), "One Hundred Twenty Three");
}