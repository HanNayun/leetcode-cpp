#ifndef LEETCODE_CC_722_H
#define LEETCODE_CC_722_H

#include <vector>
#include <string>

namespace Leetcode_722
{
    class Solution
    {
    public:
        std::vector<std::string> removeComments(std::vector<std::string>& source)
        {
            std::vector<std::string> res;
            std::string new_line;
            bool in_block = false;
            for (auto& line: source)
            {
                for (int i = 0; i < line.size(); i++)
                {
                    if (in_block)
                    {
                        if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/')
                        {
                            in_block = false;
                            i++;
                        }
                    }
                    else
                    {
                        if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*')
                        {
                            in_block = true;
                            i++;
                        }
                        else if (i + 1 < line.size() & line[i] == '/' && line[i + 1] == '/')
                        {
                            break;
                        }
                        else
                        {
                            new_line += line[i];
                        }
                    }
                }

                if (!in_block && !new_line.empty())
                {
                    res.push_back(new_line);
                    new_line = "";
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_CC_722_H
