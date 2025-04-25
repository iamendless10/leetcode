class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        minlen = float('inf') 
        currsum = 0
        left = 0

        for right in range(len(nums)):
            currsum += nums[right]

            while currsum >= target:
                minlen = min(minlen, right - left + 1)
                currsum -= nums[left]
                left += 1

        return minlen if minlen != float('inf') else 0
