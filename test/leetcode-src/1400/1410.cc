#include "leetcode_src/1400/1410.h"
#include <gtest/gtest.h>

TEST(Test1410, NormalCase)
{
    auto solution{leetcode_1410::Solution()};
    auto input{std::string{"&amp; is an HTML entity but &ambassador; is not."}};
    EXPECT_EQ(solution.entityParser(input), "& is an HTML entity but &ambassador; is not.");

    input = std::string{"and I quote: &quot;...&quot;"};
    EXPECT_EQ(solution.entityParser(input), "and I quote: \"...\"");

    input = "&amp;amp;";
    EXPECT_EQ(solution.entityParser(input), "&amp;");

    input = "&&gt;";
    EXPECT_EQ(solution.entityParser(input), "&>");
}