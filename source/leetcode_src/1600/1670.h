#pragma once

#include <deque>

namespace leetcode_1670{
class FrontMiddleBackQueue
{
public:
    void pushFront(int val)
    {
        left_.push_front(val);
        Balance();
    }

    void pushMiddle(int val)
    {
        if (left_.size() > right_.size())
        {
            right_.push_front(left_.back());
            left_.pop_back();
        }

        left_.push_back(val);
        Balance();
    }

    void pushBack(int val)
    {
        right_.push_back(val);
        Balance();
    }

    int popFront()
    {
        if (left_.empty())
            return -1;

        auto res = left_.front();
        left_.pop_front();
        Balance();
        return res;
    }

    int popMiddle()
    {
        if (left_.empty())
            return -1;

        auto res = left_.back();
        left_.pop_back();
        Balance();
        return res;
    }

    int popBack()
    {
        if (left_.empty())
            return -1;

        auto res = right_.empty() ? left_.back() : right_.back();
        if (right_.empty())
            left_.pop_back();
        else
            right_.pop_back();

        Balance();
        return res;
    }

private:
    void Balance()
    {
        if (left_.size() > right_.size() + 1)
        {
            right_.push_front(left_.back());
            left_.pop_back();
        }
        else if (left_.size() < right_.size())
        {
            left_.push_back(right_.front());
            right_.pop_front();
        }
    }

    std::deque<int> left_;
    std::deque<int> right_;
};
}
