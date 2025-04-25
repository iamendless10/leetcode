class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        def cc(start, end):
            while start < end:
                nums[start],nums[end] = nums[end],nums[start]
                start += 1
                end -=1
        n = len(nums)
        k %= n

        cc(0, n - 1)
        cc(0, k - 1)
        cc(k, n - 1)