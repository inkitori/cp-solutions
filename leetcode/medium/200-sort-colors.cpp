class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0, 0, 0};

        for (int i = 0; i < nums.size(); i++)
        {
            cnt[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt[0] > 0)
            {
                cnt[0]--;
                nums[i] = 0;
            }
            else if (cnt[1] > 0)
            {
                cnt[1]--;
                nums[i] = 1;
            }
            else if (cnt[2] > 0)
            {
                cnt[2]--;
                nums[i] = 2;
            }
        }
        
    }
};