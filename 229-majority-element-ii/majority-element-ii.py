class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        threshold = n // 3
        result = []
        
        for num in set(nums): 
            count = nums.count(num) 
            if count > threshold:
                result.append(num)
        
        return result
