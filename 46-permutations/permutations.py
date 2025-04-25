class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        from itertools import permutations
        perm = permutations(nums)
        return list(perm)
        