class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxpro = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                maxpro += prices[i] - prices[i-1]
        return maxpro