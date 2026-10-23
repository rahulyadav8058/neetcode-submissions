"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        n = len(intervals)
        for i in range(n):
            a = intervals[i]
            for j in range(i+1,n):
                b = intervals[j]
                if min(a.end,b.end) > max(a.start,b.start):
                    return False
        return True
