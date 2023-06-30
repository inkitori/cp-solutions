class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0, end = 0;
        int ans = -1000000;
        int sum = 0;
        
        while (end != nums.size()) {
            sum += nums[end];
            if (nums[end] > sum) {
                sum = nums[end];
                start = end;
            }
            
            ++end;
            
            ans = max(ans, sum);
        }
        
        return ans;
        
    }
};