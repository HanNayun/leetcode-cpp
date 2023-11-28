#pragma once

#include <deque>
#include <iostream>

//1. Types and type aliases (typedef, using, enum, nested structs and classes, and friend types)
//(Optionally, for structs only) non-static data members
//2. Static constants
//3. Factory functions
//4. Constructors and assignment operators
//5. Destructor
//6. All other functions (static and non-static member functions, and friend functions)
//7. All other data members (static and non-static)


namespace leetcode_1670
{
    class FrontMiddleBackQueue
    {
    public:
        FrontMiddleBackQueue()
        {
        }

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

    private:
        std::deque<int> left_;
        std::deque<int> right_;


    };
}