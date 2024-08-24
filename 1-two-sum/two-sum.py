class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        res=[]
        for n, i in enumerate(nums):
            diff = target - i
            if diff in hashmap:
                return [hashmap[diff],n]
            else:
                hashmap[i]=n
        return res        