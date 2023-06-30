class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> table(nums.size(), 1);
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    table[i] = max(table[j] + 1, table[i]);
                }
            }
        }
        
        for (int i : table) ans = max(ans, i);
        return ans;
    }
};