class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 100001;
        int ans = 0;
        
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else ans = max(ans, prices[i] - buy);
        }
        
        return ans;
        
    }
};