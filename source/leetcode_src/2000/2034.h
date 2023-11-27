#ifndef LEETCODE_CC_2034_H
#define LEETCODE_CC_2034_H

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

namespace Leetcode_2034
{
    class StockPrice
    {
    private:
        std::unordered_map<int, int> _stock_prices;
        std::multiset<int> _prices;
        int _latest_time_stamp{};

    public:
        StockPrice() = default;

        void update(int timestamp, int price)
        {
            if (_prices.empty())
            {
                _latest_time_stamp = timestamp;
            }

            if (_stock_prices.count(timestamp))
            {
                _prices.erase(_prices.find(_stock_prices[timestamp]));
            }

            _prices.insert(price);
            _latest_time_stamp = std::max(_latest_time_stamp, timestamp);
            _stock_prices[timestamp] = price;
        }

        int current()
        {
            return _stock_prices[_latest_time_stamp];
        }

        int maximum()
        {
            return *_prices.rbegin();
        }

        int minimum()
        {
            return *_prices.begin();
        }
    };
}
#endif //LEETCODE_CC_2034_H
