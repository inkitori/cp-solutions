class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        memory = None
        index = 0
        
        for dummy in range(len(nums)):
            try:
                if nums[index] == memory:
                    del nums[index]
                else:
                    memory = nums[index]
                    index += 1
            except IndexError:
                break