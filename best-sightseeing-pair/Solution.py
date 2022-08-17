// https://leetcode.com/problems/best-sightseeing-pair

class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        net_val = [0]*len(values)
        for i,v in enumerate(values):
            net_val[i] = v-i
        running_max = values[0] 
        ans = 0
        for i in range(1,len(net_val)):
            ans = max(ans, net_val[i] + running_max)
            running_max = max(running_max, values[i]+i)
        
        return ans
            
            