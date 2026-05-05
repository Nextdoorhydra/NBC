#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> buy;
    vector<int> sell;
    vector<int> cooldown;

    int maxProfit(vector<int>& prices) {
        auto eval = [](int a, int b) { return a - b > 0 ? a - b : 0; };
        buy = vector<int>(prices.size(), -1);
        sell = vector<int>(prices.size(), -1);
        cooldown = vector<int>(prices.size(), -1);

        buy[0] = 0;
        sell[0] = 0;
        cooldown[0] = 0;

        for (int i = 1; i < prices.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                // 판매
                int profit = eval(prices[i], prices[j]);

                if (profit != 0) {
                    sell[i] = max(sell[i], profit + buy[j]);
                }

            }
            // 쉬었음
            cooldown[i] = sell[i - 1];

            // 구매
            buy[i] = max(cooldown[i - 1], buy[i - 1]);
        }

        return max({ buy[buy.size() - 1], sell[sell.size() - 1], cooldown[cooldown.size() - 1] });
    }
};