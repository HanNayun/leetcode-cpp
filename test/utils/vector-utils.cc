#include "vector-utils.h"

void utils::VectorUtils::TestFristKthElemnetSame(const std::vector<int>& vec1,
                                                 const std::vector<int>& vec2,
                                                 int k)
{
    {
        for (int i = 0; i < k; ++i)
            EXPECT_EQ(vec1[i], vec2[i]);
    }
}
