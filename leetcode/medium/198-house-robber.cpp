class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> table(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (i - 2 < 0) table[i] = nums[i];
            else if (i - 3 < 0) table[i] = nums[i] + table[i - 2];
            else table[i] = nums[i] + max(table[i-2], table[i - 3]);
        }
        
        if (table.size() > 1) return max(table[nums.size() - 1], table[nums.size() - 2]);
        else return table[nums.size() - 1];
    }
};