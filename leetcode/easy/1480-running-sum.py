class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        sum_array = []
        current_sum = 0
        
        for i in range(len(nums)):
            current_sum += nums[i]
            sum_array.append(current_sum)
            
        return sum_array