// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks

class Solution:

    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        dp=defaultdict(lambda:int(10**7))
        def solve(stime, mask):
            if dp[(stime, mask)] != int(10**7):
                return dp[(stime, mask)]
            if mask == 0:
                return 0
            flag=False
            for i, t in enumerate(tasks):
                if ((mask>>i) & 1) == 1:
                    if tasks[i]<=stime:
                        dp[(stime, mask)]=min(dp[(stime, mask)], solve(stime-t, mask ^ (1<<i)))
                        flag=True
            if not flag:        
                dp[(stime, mask)]=min(dp[(stime, mask)], 1+solve(sessionTime, mask))
            return dp[(stime, mask)]
        return 1+solve(sessionTime, int(2**len(tasks))-1)