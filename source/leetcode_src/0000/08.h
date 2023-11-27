#pragma once

#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

namespace leetcode_08
{
    class Automaton
    {
    public:
        int sign_ = 1;
        long long res_ = 0;

        void input(const char& c)
        {
            state_ = table_[state_][GetNextStatePos(c)];

            if (state_ == State::kInNumber)
            {
                res_ = res_ * 10 + (c - '0');

                if (IsExceedInt32(res_ * sign_))
                {
                    state_ = State::kEnd;
                    res_ = sign_ == 1
                           ? INT32_MAX
                           : INT32_MIN;
                }

            }
            else if (state_ == State::kSigned)
            {
                sign_ = c == '+' ? 1 : -1;
            }
        }

        bool IsEnd()
        {
            return state_ == State::kEnd;
        }

        [[nodiscard]]
        int ParseRes() const
        {
            return static_cast<int>(res_ * sign_);
        }

    private:
        enum class State
        {
            kStart,
            kSigned,
            kInNumber,
            kEnd
        };

        std::unordered_map<State, std::vector<State>> table_ = {
                {State::kStart,    {State::kStart, State::kSigned, State::kInNumber, State::kEnd}},
                {State::kSigned,   {State::kEnd,   State::kEnd,    State::kInNumber, State::kEnd}},
                {State::kInNumber, {State::kEnd,   State::kEnd,    State::kInNumber, State::kEnd}},
                {State::kEnd,      {State::kEnd,   State::kEnd,    State::kEnd,      State::kEnd}}
        };

        State state_ = State::kStart;

        static int GetNextStatePos(const char& c)
        {
            if (c == ' ') return 0;
            if (c == '+' || c == '-') return 1;
            if (isdigit(c)) return 2;
            return 3;
        }

        static bool IsExceedInt32(long long num)
        {
            return num > INT32_MAX || num < INT32_MIN;
        }
    };

    class Solution
    {
    public:
        int myAtoi(std::string s)
        {
            auto automaton{Automaton()};
            std::find_if(s.begin(), s.end(), [&automaton](const char& c) -> bool
            {
                automaton.input(c);
                return automaton.IsEnd();
            });

            return automaton.ParseRes();
        }
    };
}
