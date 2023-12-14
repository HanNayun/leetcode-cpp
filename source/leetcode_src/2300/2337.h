#pragma once

#include <string>

using std::string;

class Solution
{

public:
    bool canChange(string start, string target)
    {

        auto n = start.size();
        int p1 = 0;
        int p2 = 0;

        while (p1 < n && p2 < n)
        {
            while (start[p1] == '_')
                p1++;

            while (target[p2] == '_')
                p2++;

            if (start[p1] != target[p2] || target[p2] == 'L' && p1 < p2 || target[p2] == 'R' && p1 > p2)
                return false;

            p1++;
            p2++;
        }

        while (p1 < n)
            if (start[p1++] != '_')
                return false;

        while (p2 < n)
            if (target[p2++] != '_')
                return false;

        return true;
    }
};

