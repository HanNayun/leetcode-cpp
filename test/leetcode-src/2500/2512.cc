#include "leetcode_src/2500/2512.h"

#include "gtest/gtest.h"

TEST(Test_2512, Case_0)
{
    leetcode_2512::Solution solution;
    std::vector<std::string> positive_feedback{"smart", "brilliant", "studious"};
    std::vector<std::string> negative_feedback{"not"};
    std::vector<std::string> report{"this student is studious", "the student is smart"};
    std::vector<int> student_id{1, 2};
    int k{2};

    auto result = solution.topStudents(positive_feedback, negative_feedback, report, student_id, k);
    auto expected = std::vector<int>{1, 2};
    EXPECT_EQ(result, expected);
}

TEST(Test_2512, Case_1)
{
    leetcode_2512::Solution solution;
    std::vector<std::string> positive_feedback{"smart", "brilliant", "studious"};
    std::vector<std::string> negative_feedback{"not"};
    std::vector<std::string> report{"this student is not studious", "the student is smart"};
    std::vector<int> student_id{1, 2};
    int k{2};

    auto result = solution.topStudents(positive_feedback, negative_feedback, report, student_id, k);
    auto expected = std::vector<int>{2, 1};
    EXPECT_EQ(result, expected);
}
