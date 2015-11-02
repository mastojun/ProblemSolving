/**
 * O(n^2) 당연 TLE!
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for(int i = 0; i < prices.size(); i++) {
            result = max(result, getMax(prices, 0, i) + getMax(prices, i, prices.size()));
        }
        return result;
    }
private:
    int getMax(vector<int>& prices, int s, int e) {
        int result = 0;
        int m = prices[s];
        for(int i = s; i < e; i++) {
            m = min(m, prices[i]);
            result = max(result, prices[i] - m);
        }
        return result;
    }
};

