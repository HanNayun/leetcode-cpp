#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

namespace leetcode_2512
{
    class Solution
    {
    public:
        std::vector<int> topStudents(std::vector<std::string>& positive_feedback,
                                     std::vector<std::string>& negative_feedback,
                                     std::vector<std::string>& report,
                                     std::vector<int>& student_id, int k)
        {
            std::unordered_map<std::string, int> words;
            for (const auto& word: positive_feedback)
                words[word] = 3;

            for (const auto& word: negative_feedback)
                words[word] = -1;

            std::vector<std::vector<int>> result;
            for (int i = 0; i < report.size(); i++)
            {
                std::stringstream ss;
                std::string w;
                int score{0};
                ss << report[i];
                while (ss >> w)
                    if (words.count(w))
                        score += words[w];

                result.push_back({-score, student_id[i]});
            }
            sort(result.begin(), result.end());
            std::vector<int> top_k;
            top_k.reserve(k);
            for (int i = 0; i < k; i++)
                top_k.push_back(result[i][1]);

            return top_k;
        }
    };

}

