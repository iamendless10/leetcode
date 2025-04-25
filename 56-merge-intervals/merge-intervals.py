class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res =[]
        intervals.sort()
        res.append(intervals[0])

        for i in range(1, len(intervals)):
            if intervals[i][0] <= res[-1][1]:
                res[-1][1] = max(intervals[i][1], res[-1][1])
            else:
                res.append(intervals[i])
        return res
        