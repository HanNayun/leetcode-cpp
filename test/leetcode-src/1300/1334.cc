#include "leetcode_src/1300/1334.h"

#include <gtest/gtest.h>

TEST(LeetCode1334Solution, ReturnsCorrectCityWithFewestNeighborsWithinThreshold)
{
    leetcode_1334::Solution solution;
    std::vector<std::vector<int>> edges = {{0, 1, 3},
                                           {1, 2, 1},
                                           {2, 3, 4},
                                           {2, 0, 2}};
    int n = 4;
    int distance_threshold = 4;
    int expected_city = 3;
    ASSERT_EQ(solution.findTheCity(n, edges, distance_threshold), expected_city);
}

TEST(LeetCode1334Solution, ReturnsCorrectCityWhenAllCitiesAreWithinThreshold)
{
    leetcode_1334::Solution solution;
    std::vector<std::vector<int>> edges = {{0, 1, 1},
                                           {1, 2, 1},
                                           {2, 0, 1}};
    int n = 3;
    int distance_threshold = 2;
    int expected_city = 2;
    ASSERT_EQ(solution.findTheCity(n, edges, distance_threshold), expected_city);
}

TEST(LeetCode1334Solution, ReturnsCorrectCityWhenNoCitiesAreWithinThreshold)
{
    leetcode_1334::Solution solution;
    std::vector<std::vector<int>> edges = {{0, 1, 5},
                                           {1, 2, 5},
                                           {2, 0, 5}};
    int n = 3;
    int distance_threshold = 4;
    int expected_city = 2;
    ASSERT_EQ(solution.findTheCity(n, edges, distance_threshold), expected_city);
}

TEST(LeetCode1334Solution, ReturnsCorrectCityWhenThereIsOnlyOneCity)
{
    leetcode_1334::Solution solution;
    std::vector<std::vector<int>> edges = {};
    int n = 1;
    int distance_threshold = 0;
    int expected_city = 0;
    ASSERT_EQ(solution.findTheCity(n, edges, distance_threshold), expected_city);
}