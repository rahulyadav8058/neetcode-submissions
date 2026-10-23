class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda pair: pair[0])
        ans = []

        for i in range(len(intervals)):
            start = intervals[i][0]
            end = intervals[i][1]
            if len(ans) ==0 or ans[-1][1]<start:
                ans.append([start,end])
            else:
                ans[-1][1] = max(ans[-1][1],end)
        return ans