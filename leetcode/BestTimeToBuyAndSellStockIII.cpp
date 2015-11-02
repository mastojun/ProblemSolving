/**
 * 0..i 지점까지는 순차 방향에서 (0 .. i 까지의 minimum값과 i의 차이) 와 현재까지의 최댓값
 * i + 1 .. end 까지는 역 방향에서 (i + 1 .. end 까지의 maximum값과 i의 차이)와 현재까지의 최댓값
 *
 * 을 미리 구해놓으면 O(n^2)솔루션에서 했던 것 처럼 매번 다 계산할 필요가 없음....을, O(n^2)에서 불필요한 계산 줄이다가 발견함..
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        vector<int> backward = backwardTable(prices);
        vector<int> forward = forwardTable(prices);

        int result = 0;
        for(int i = 0; i < prices.size(); i++) {
            result = max(result, backward[i] + forward[i]);
        }

        return result;
    }
private:
    vector<int> backwardTable(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);

        int M = prices[prices.size() - 1];
        for(int i = prices.size() - 2; i >= 0; i--) {
            M = max(M, prices[i]);
            dp[i] = max(dp[i + 1], M - prices[i]);
        }

        return dp;
    }

    vector<int> forwardTable(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);

        int m = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            m = min(m, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - m);
        }

        return dp;
    }
};

