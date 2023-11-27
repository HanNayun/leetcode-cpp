#include "gtest/gtest.h"
#include "leetcode_src/2000/2034.h"

TEST(Test_2034, Case_0)
{
    auto stock_price = Leetcode_2034::StockPrice{};
    stock_price.update(1, 10);
    stock_price.update(2, 5);

    EXPECT_EQ(stock_price.current(), 5);
    EXPECT_EQ(stock_price.maximum(), 10);
    stock_price.update(1, 3);
    EXPECT_EQ(stock_price.maximum(), 5);
    stock_price.update(4, 2);
    EXPECT_EQ(stock_price.minimum(), 2);
}