class Solution {
public:
    /**
     * dp(i, state): maximal profit you can get after day i'th, at state
     *
     * dp(i, 0) = max(dp(i+1, 0), dp(i+1, 1) - price[i])
     * dp(i, 1) = max(dp(i+1, 1), price[i] + dp(i+1, 0))
     * dp(n, 0) = 0
     * dp(n, 1) = -price[n]
     */
    int maxProfit(vector<int>& prices) {
        int num_days = prices.size();
        int res = 0x1 << 31;
        int state[2] = {0, -prices[num_days - 1]};

        int next_state_0, next_state_1;
        for (int i = num_days - 1; i >= 0; i--) {
            next_state_0 = max(state[0], state[1] - prices[i]);
            res = max(res, next_state_0);
            next_state_1 = max(state[1], state[0] + prices[i]);
            state[0] = next_state_0;
            state[1] = next_state_1;
        }

        return res;
    }
};