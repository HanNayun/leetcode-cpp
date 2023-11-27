#include "leetcode_src/0500/504.h"
#include <gtest/gtest.h>

TEST(Test504, NormalCase)
{
    auto solution{leetcode_504::Solution()};
    
    EXPECT_EQ(solution.convertToBase7(100), "202");
    EXPECT_EQ(solution.convertToBase7(-7), "-10");
}